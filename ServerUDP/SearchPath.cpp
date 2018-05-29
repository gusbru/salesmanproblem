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

void SearchPath::start(int cli_fd)
{
    std::cout << "Starting search..." << std::endl;

    this->cli_fd = cli_fd;
    PairPathCost pairPathCost(cityConnections.getCities());

    // add origin
    currentCity = cityConnections.getCity(startCity);
    currentPath.emplace_back(currentCity.getName());
    currentCost = 0.0;
    pairPathCost.addCity(currentCity, currentCost);
    citiesStack.emplace(pairPathCost);
    double cost, nextCost;
    int count = 0;
    std::string lowestCostString;
    PairPathCost pairPathCostNext;

    while (!citiesStack.empty() && count < 2)
    {

        // remove the top pairPathCost in the stack --> next city to visit
        pairPathCost = citiesStack.top();
        citiesStack.pop();

        if (isSolution(pairPathCost, startCity))
        {
            // compare cost
            count++;
            std::vector<std::string> path{};
            path = pairPathCost.getPath();
            cost = pairPathCost.getCost() + cityConnections.getCity(path.back()).getNeighborDistance(startCity);
            path.emplace_back(startCity);

            if (lowestCost < 0)
            {
                lowestCost = cost;
                shortestPath = path;
            }
            else
            {
                if (cost < lowestCost)
                {
                    lowestCost = cost;
                    shortestPath = path;
                }
            }
            // send the solution to client
            std::string shortestPathString;
            for (auto &c : shortestPath)
                shortestPathString += c + ";";

            sendToClient(shortestPathString);

            lowestCostString = std::to_string(lowestCost);
            sendToClient(lowestCostString);
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
            for (auto &n : currentCity.getNeighborsName())
            {
                if (!pairPathCost.getCity(n).isVisited())
                    addToStack(pairPathCost, n);

                if (currentCity.getNumNeighbors() == 1)
                    addToStack(pairPathCost, n);

                // for cities with only one road (e.g. Albuquerque)
//                if (currentCity.getNumNeighbors() == 1)
//                {
//                    pairPathCostNext = pairPathCost;
//                    City nextCity = cityConnections.getCity(n);
//                    nextCost = currentCity.getNeighborDistance(n);
//                    pairPathCostNext.addCity(nextCity, nextCost);
//                    citiesStack.emplace(pairPathCostNext);
//                }
//
//                if (!pairPathCost.getCity(n).isVisited())
//                {
//                    pairPathCostNext = pairPathCost;
//                    City nextCity = cityConnections.getCity(n);
//                    nextCost = currentCity.getNeighborDistance(n);
//                    pairPathCostNext.addCity(nextCity, nextCost);
//                    citiesStack.emplace(pairPathCostNext);
//                }
            }
        }
    }

    std::cout << "Found " << count << " solutions";
    if (count == 0)
        std::cout << " :(" << std::endl;
    else
        std::cout << " :)" << std::endl;

    // send a message to client that the calculation is finished
    sendToClient("END");
    sendToClient("0");

}

bool SearchPath::isSolution(PairPathCost pairPathCost, std::string initialCity)
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

std::string SearchPath::getRoute()
{
    std::string ret;
    for (auto &c : shortestPath)
        ret += c + ";";

    return ret;
}

std::string SearchPath::getCost()
{
    return std::to_string(this->lowestCost);
}

ssize_t SearchPath::sendToClient(std::string stringToSend)
{
    stringToSend += "\n";
    char charToSend[BUFSIZE] = "";
    strncpy(charToSend, stringToSend.c_str(), strlen(stringToSend.c_str()));
    ssize_t status = write(cli_fd, charToSend, sizeof(charToSend));

    return status;
}

void SearchPath::addToStack(PairPathCost pairPathCost, std::string neighborName)
{
    PairPathCost pairPathCostNext = pairPathCost;
    City nextCity = cityConnections.getCity(neighborName);
    double nextCost = currentCity.getNeighborDistance(neighborName);
    pairPathCostNext.addCity(nextCity, nextCost);
    citiesStack.emplace(pairPathCostNext);
}

bool SearchPath::isSolution(PairPathCost pairPathCost, std::string initialCity, std::string endCity)
{
    return false;
}
