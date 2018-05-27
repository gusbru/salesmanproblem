//
// Created by Gustavo Brunetto on 19/05/18.
//

#ifndef SERVERUDP_SEARCHPATH_H
#define SERVERUDP_SEARCHPATH_H

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include "CityConnections.h"
#include "PairPathCost.h"

class SearchPath
{
public:
    explicit SearchPath(std::string startCity);
    void start();

private:
    std::string startCity;
    std::vector<std::string> shortestPath{}, currentPath;
    double lowerCost = -1.0, currentCost = 0.0;
    std::stack<PairPathCost> citiesStack;
    City currentCity, previousCity;
    CityConnections cityConnections;

    bool isSolution(PairPathCost pairPathCost, std::string initialCity);

};


#endif //SERVERUDP_SEARCHPATH_H
