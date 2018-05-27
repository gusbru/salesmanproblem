//
// Created by Gustavo Brunetto on 19/05/18.
//

#include "SearchPath.h"

SearchPath::SearchPath(std::string startCity) : startCity(startCity)
{
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


    while (!citiesStack.empty())
    {
        // remove the top pairPathCost in the stack --> next city to visit
        pairPathCost = citiesStack.top();
        citiesStack.pop();

        if (isSolution(pairPathCost, startCity))
        {
            // compare cost
            std::cout << "**************************************" << std::endl;
            std::cout << "FOUND A SOLUTION" << std::endl;
            std::cout << "**************************************" << std::endl;
            exit(0);

        }
        else
        {
            currentPath  = pairPathCost.getPath();
            currentCost  = pairPathCost.getCost();
            currentCity  = pairPathCost.getCity(currentPath.back());


            std::cout << "Current path = ";
            for (auto &c : currentPath)
            {
                std::cout << c << "->";
            }
            std::cout << "\nCost = " << currentCost << std::endl;

            std::cout << "I am at " << currentCity.getName();
            std::cout << " looking at neighbors: ";
            for (auto &n : currentCity.getNeighborsName())
                if (!pairPathCost.getCity(n).isVisited())
                    std::cout << n << " ( d=" << currentCity.getNeighborDistance(n) << "), ";

            std::cout << std::endl;

            // add all non visited neighbors to stack;
            int numAvailableNeighbors = 0;
            for (auto &n : currentCity.getNeighborsName())
            {

                if (!pairPathCost.getCity(n).isVisited())
                {
                    PairPathCost pairPathCostNext = pairPathCost;
                    City nextCity = cityConnections.getCity(n);
                    double nextCost = currentCity.getNeighborDistance(n);
                    pairPathCostNext.addCity(nextCity, nextCost);
                    citiesStack.emplace(pairPathCostNext);
                    numAvailableNeighbors++;
                }

            }

            std::cin.get();

        }

    }


}

bool SearchPath::isSolution(PairPathCost pairPathCost, std::string initialCity)
{
    if (pairPathCost.getNumberOfVisitedCities() < cityConnections.getNumberOfCities())
        return false;

    // get a list of all city names
    std::vector<std::string> path = pairPathCost.getPath();
    std::vector<std::string> listOfCities = cityConnections.getCitiesName();

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

    // se a lista de cidades estiver vazia e a ultima cidade tiver como vizinho
    // initialCity, entao path 'e uma solucao
    if (listOfCities.empty())
    {
        std::cout << "*************************************************************" << std::endl;
        std::cout << "*************************************************************" << std::endl;
        std::cout << "path found = ";
        for (auto &c : path)
        {
            std::cout << c << "->";
        }
        std::cout << std::endl;
        std::cout << "*************************************************************" << std::endl;
        std::cout << "*************************************************************" << std::endl;
        for (auto &n : cityConnections.getNeighbors(path.back()))
            if (n == initialCity) return true;
    }

    return false;

//    return listOfCities.empty();
}
