//
// Created by Gustavo Brunetto on 30/05/18.
//

#ifndef SERVERUDP_SEARCH_H
#define SERVERUDP_SEARCH_H

#include <iostream>
#include <stack>
#include "PairPathCost.h"
#include "City.h"
#include "CityConnections.h"

class Search
{
private:
    std::stack<PairPathCost> citiesStack;
    std::vector<std::string> shortestPath{}, currentPath;
    City currentCity;
    CityConnections cityConnections;
    std::string startCity;
    double cost, lowestCost, currentCost;
    PairPathCost bestPairPathCost;

    bool isSolution(PairPathCost pairPathCost, std::string initialCity);

    void addToStack(PairPathCost pairPathCost, std::string neighborName);

public:
    PairPathCost search(PairPathCost pairPathCost);
};


#endif //SERVERUDP_SEARCH_H
