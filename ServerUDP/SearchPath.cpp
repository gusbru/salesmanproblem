//
// Created by Gustavo Brunetto on 19/05/18.
//

#include "SearchPath.h"

SearchPath::SearchPath(std::string startCity) : startCity(startCity)
{
    currentCity = cityConnections.getCity(startCity);
    allCities = cityConnections.getCities();

    std::cout << "Starting from " << startCity << std::endl;

    currentPath.emplace_back(currentCity->getName());
    citiesStack.addItem(currentPath);
    currentCity->setVisited();

    shortestPath.clear();
    lowerCost = -1;
    shortestPath.emplace_back(currentCity->getName());


}

void SearchPath::start()
{
    std::cout << "Starting search..." << std::endl;
//    std::cout << "Stack = " << citiesStack.toString() << std::endl;

    double tmpCost;
    std::vector<std::string> tmpPath;

    while (!citiesStack.isEmpty())
    {

        currentPath = citiesStack.getItem().getPath();
        currentCity = cityConnections.getCity(citiesStack.getItem().getPath().back());
        currentCost = citiesStack.getItem().getCost();

        citiesStack.removeItem();

        std::cout << "Current path = ";
        for (const auto &i : currentPath)
        {
            std::cout << i << "->";
        }
        std::cout << std::endl;
        std::cout << "I am at " << currentCity->getName() << std::endl;

        if (isSolution(currentPath, startCity))
        {
            // compare cost
            std::cout << "**************************************" << std::endl;
            std::cout << "FOUND A SOLUTION" << std::endl;
            std::cout << "**************************************" << std::endl;
            exit(0);

        } else
        {
            std::cout << "Looking for:\n";
            for (auto &neighbor : currentCity->getNeighborsName())
            {
                if (!cityConnections.getCity(neighbor)->isVisited())
                {
                    std::cout << "\t" << neighbor << " at " << currentCity->getDistance(neighbor) << std::endl;
                    tmpCost = currentCost;
                    tmpPath = currentPath;
                    tmpPath.emplace_back(neighbor);
                    tmpCost += currentCity->getDistance(neighbor);
                    citiesStack.addItem(PairPathCost(tmpPath, tmpCost));
                    currentCity->setVisited();
                }

                // for the case where there is only one connection (e.g. Albuquerque)
                if (cityConnections.getCity(neighbor)->getNumNeighbors() == 1)
                {
                    std::cout << "\t" << neighbor << " at " << currentCity->getDistance(neighbor) << std::endl;
                    tmpCost = currentCost;
                    tmpPath = currentPath;
                    tmpPath.emplace_back(neighbor);
                    tmpCost += currentCity->getDistance(neighbor);
                    citiesStack.addItem(PairPathCost(tmpPath, tmpCost));
                    currentCity->setVisited();
                }

            }
            std::cout << "Stack = " << citiesStack.toString() << std::endl;
        }

    }

    std::cout << "Solution = ";
    for (const auto &i : currentPath)
    {
        std::cout << i << "->";
    }
    std::cout << std::endl;

}

bool SearchPath::isSolution(std::vector<std::string> path, std::string initialCity)
{
    if (path.size() < allCities->size())
        return false;

    // get a list of all city names
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
        for (auto &c : path) {
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
