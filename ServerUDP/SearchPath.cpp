//
// Created by Gustavo Brunetto on 19/05/18.
//

#include "SearchPath.h"

SearchPath::SearchPath(std::string startCity)
{
    // remove newline (\n) from startCity
    startCity.erase(std::remove(startCity.begin(), startCity.end(), '\n'), startCity.end());
    this->startCity = startCity;
    std::cout << "Starting from " << startCity << std::endl;
}

void SearchPath::start()
{
    std::cout << "Starting search..." << std::endl;

    PairPathCost pairPathCost(cityConnections.getCities());

    // add origin
    currentCity = cityConnections.getCity(startCity);
    currentPath.emplace_back(currentCity.getName());
    currentCost = 0.0;
    pairPathCost.addCity(currentCity, currentCost);
    citiesStack.emplace(pairPathCost);

    int count = 0;

    while (!citiesStack.empty())
    {
//        std::cout << count << std::endl;

        // remove the top pairPathCost in the stack --> next city to visit
        pairPathCost = citiesStack.top();
        citiesStack.pop();

        if (isSolution(pairPathCost, startCity))
        {
            // compare cost
            std::cout << "**************************************" << std::endl;
            std::cout << "FOUND A SOLUTION" << std::endl;
            std::cout << "**************************************" << std::endl;
            count++;

            if (lowerCost < 0)
            {
                lowerCost = currentCost;
                shortestPath = currentPath;

            }
            else
            {
                if (currentCost < lowerCost)
                {
                    lowerCost = currentCost;
                    shortestPath = currentPath;
                }
            }
        }
        else
        {
            currentPath = pairPathCost.getPath();
            currentCost = pairPathCost.getCost();
            currentCity = pairPathCost.getCity(currentPath.back());


            // Output to debug
//            std::cout << "Current path = ";
//            for (auto &c : currentPath)
//            {
//                std::cout << c << "->";
//            }
//            std::cout << "\nCost = " << currentCost << std::endl;

//            std::cout << "I am at " << currentCity.getName();
//            std::cout << " looking at neighbors: ";
//            for (auto &n : currentCity.getNeighborsName())
//                if (!pairPathCost.getCity(n).isVisited())
//                    std::cout << n << " ( d=" << currentCity.getNeighborDistance(n) << "), ";
//
//            std::cout << std::endl;

            // add all non visited neighbors to stack;
            int numAvailableNeighbors;
            for (auto &n : currentCity.getNeighborsName())
            {
                numAvailableNeighbors = 0;
                // for cities with only one road (e.g. Albuquerque)
                if (currentCity.getNumNeighbors() == 1)
                {
                    PairPathCost pairPathCostNext = pairPathCost;
                    City nextCity = cityConnections.getCity(n);
                    double nextCost = currentCity.getNeighborDistance(n);
                    pairPathCostNext.addCity(nextCity, nextCost);
                    citiesStack.emplace(pairPathCostNext);
                    numAvailableNeighbors++;
                }

                if (!pairPathCost.getCity(n).isVisited())
                {
                    PairPathCost pairPathCostNext = pairPathCost;
                    City nextCity = cityConnections.getCity(n);
                    double nextCost = currentCity.getNeighborDistance(n);
                    pairPathCostNext.addCity(nextCity, nextCost);
                    citiesStack.emplace(pairPathCostNext);
                    numAvailableNeighbors++;

                }

//                std::cout << "***********************" << std::endl;
//                std::cout << "***********************" << std::endl;
//                std::cout << "number of " << numAvailableNeighbors << std::endl;
//                std::cout << "***********************" << std::endl;
//                std::cout << "***********************" << std::endl;



            }

//            std::cin.get();
//            count++;

        }

    }

    std::cout << "Found " << count << " solutions";
    if (count == 0)
        std::cout << " :(" << std::endl;
    else
        std::cout << " :)" << std::endl;


}

bool SearchPath::isSolution(PairPathCost pairPathCost, std::string initialCity)
{
    if (pairPathCost.getNumberOfVisitedCities() < cityConnections.getNumberOfCities())
        return false;



    // get a list of all city names
    std::vector<std::string> path = pairPathCost.getPath();
    std::vector<std::string> listOfCities = cityConnections.getCitiesName();


    std::cout << "Path = ";
    for (auto &c : path)
        std::cout << c << "->";
    std::cout << std::endl;

    // check which cities were visited
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
        return false;
    }


//    std::cin.get();

    // se a lista de cidades estiver vazia e a ultima cidade tiver como vizinho
    // initialCity, entao path 'e uma solucao
    for (auto &n : cityConnections.getNeighbors(path.back()))
        if (n == initialCity)
        {
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

std::string SearchPath::getRoute()
{
    std::string ret;
    for (auto &c : shortestPath)
        ret += c + ";";

    return ret;
}

std::string SearchPath::getCost()
{
    return std::to_string(this->lowerCost);
}
