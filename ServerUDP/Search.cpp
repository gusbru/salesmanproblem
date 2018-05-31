//
// Created by Gustavo Brunetto on 30/05/18.
//

#include "Search.h"

PairPathCost Search::search(PairPathCost pairPathCost)
{

    citiesStack.emplace(pairPathCost);
    currentCity = cityConnections.getCity(pairPathCost.getPath().back());


    while (!citiesStack.empty())
    {

        // remove the top pairPathCost in the stack --> next city to visit
        pairPathCost = citiesStack.top();
        citiesStack.pop();

        if (isSolution(pairPathCost, startCity))
        {
            // compare cost
            std::vector<std::string> path{};
            path = pairPathCost.getPath();
            cost = pairPathCost.getCost() + cityConnections.getCity(path.back()).getNeighborDistance(startCity);
            path.emplace_back(startCity);

            if (lowestCost < 0)
            {
                lowestCost = cost;
                shortestPath = path;
                bestPairPathCost = pairPathCost;
            }
            else
            {
                if (cost < lowestCost)
                {
                    lowestCost = cost;
                    shortestPath = path;
                    bestPairPathCost = pairPathCost;
                }
            }

        }
        else
        {
            currentPath = pairPathCost.getPath();
            currentCost = pairPathCost.getCost();
            currentCity = pairPathCost.getCity(currentPath.back());

            /*
             * if the current cost is higher than a best result found previously,
             * skip this branch
             **/
            if (currentCost > lowestCost && lowestCost > 0)
                break;

            // add all non visited neighbors to stack;
            for (auto &n : currentCity.getNeighborsName())
            {
                if (!pairPathCost.getCity(n).isVisited())
                    addToStack(pairPathCost, n);

                if (currentCity.getNumNeighbors() == 1)
                    addToStack(pairPathCost, n);
            }
        }
    }

    return bestPairPathCost;
}

bool Search::isSolution(PairPathCost pairPathCost, std::string initialCity)
{
    if (pairPathCost.getNumberOfVisitedCities() < cityConnections.getNumberOfCities())
        return false;

    // get a list of all city names
    std::vector<std::string> path = pairPathCost.getPath();
    std::vector<std::string> listOfCities = cityConnections.getCitiesName();

    // check if the last visited city makes connection with the start city
    int numNeighbors = 0;
    for (auto &n : cityConnections.getNeighbors(path.back()))
        if (n == initialCity)
            numNeighbors++;

    if (numNeighbors == 0)
        return false;

//     check which cities were visited
    for (auto &p : path)
    {
        for (int i = 0; i < listOfCities.size(); i++)
        {
            if (listOfCities[i] == p)
            {
                listOfCities.erase(listOfCities.begin() + i);
                break;
            }
        }
    }

    if (!listOfCities.empty())
    {
        std::cout << "not a solution because not visited all cities " << listOfCities.size() << std::endl;
        for (auto &c : listOfCities)
            std::cout << c << " ";
        std::cout << std::endl;
        for (auto &c : path)
            std::cout << c << "->";
        std::cout << std::endl;
        return false;
    }


//    std::cin.get();

    // se a lista de cidades estiver vazia e a ultima cidade tiver como vizinho
    // initialCity, entao path 'e uma solucao
    for (auto &n : cityConnections.getNeighbors(path.back()))
        if (n == initialCity)
        {
            std::cout << "*************************************************************" << std::endl;
            std::cout << "FOUND A SOLUTION" << std::endl;
            std::cout << "*************************************************************" << std::endl;
            std::cout << "*************************************************************" << std::endl;
            std::cout << "*************************************************************" << std::endl;
            std::cout << "path found = ";
            for (auto &c : path)
                std::cout << c << "->";
            std::cout << initialCity << std::endl;
            std::cout << " cost = "
                      << pairPathCost.getCost() + cityConnections.getCity(path.back()).getNeighborDistance(initialCity);
            std::cout << std::endl;
            std::cout << "*************************************************************" << std::endl;
            std::cout << "*************************************************************" << std::endl;
            return true;
        }

    return false;

//    return listOfCities.empty();
}

void Search::addToStack(PairPathCost pairPathCost, std::string neighborName)
{
    PairPathCost pairPathCostNext = pairPathCost;
    City nextCity = cityConnections.getCity(neighborName);
    double nextCost = currentCity.getNeighborDistance(neighborName);
    pairPathCostNext.addCity(nextCity, nextCost);
    citiesStack.emplace(pairPathCostNext);
}