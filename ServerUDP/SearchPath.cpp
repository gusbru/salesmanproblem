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

        if (isSolution(currentPath))
        {
            // compare cost
        }
        else
        {
            std::cout << "Looking for:\n";
            for (auto &neighbor : currentCity->getNeighborsName())
            {
                if (!cityConnections.getCity(neighbor)->isVisited()) {
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


}

bool SearchPath::isSolution(std::vector<std::string> path)
{
    if (path.size() < allCities->size())
        return false;

    if (currentCity->getName() != path.back())
        return false;

//    int count = 0;
//    for (auto &city : allCities) {
//        for (int i = 0; i < path.size(); i++) {
//            if (city == path[i]) {
//                count++;
//                break;
//            }
//        }
//    }
}
