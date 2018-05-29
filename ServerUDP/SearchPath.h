//
// Created by Gustavo Brunetto on 19/05/18.
//

#ifndef SERVERUDP_SEARCHPATH_H
#define SERVERUDP_SEARCHPATH_H

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unistd.h>
#include "CityConnections.h"
#include "PairPathCost.h"
#include "port.h"

class SearchPath
{
public:
    explicit SearchPath(std::string startCity);
    void start(int cli_fd);
    std::string getRoute();
    std::string getCost();

private:
    int cli_fd;
    std::string startCity;
    std::vector<std::string> shortestPath{}, currentPath;
    double lowestCost = -1.0, currentCost = 0.0;
    std::stack<PairPathCost> citiesStack;
    City currentCity;
    CityConnections cityConnections;

    bool isSolution(PairPathCost pairPathCost, std::string initialCity);

    bool isSolution(PairPathCost pairPathCost, std::string initialCity, std::string endCity);

    ssize_t sendToClient(std::string stringToSend);

    void addToStack(PairPathCost pairPathCost, std::string neighborName);

};


#endif //SERVERUDP_SEARCHPATH_H
