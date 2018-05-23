//
// Created by Gustavo Brunetto on 19/05/18.
//

#ifndef SERVERUDP_SEARCHPATH_H
#define SERVERUDP_SEARCHPATH_H

#include <iostream>
#include <string>
#include <vector>
#include "Stack.h"
#include "CityConnections.h"
#include "PairPathCost.h"

class SearchPath
{
public:
    explicit SearchPath(std::string startCity);
    void start();

private:
    std::string startCity;
    std::vector<City> *allCities;
    std::vector<std::string> shortestPath, currentPath;
    double lowerCost, currentCost;
    Stack citiesStack;
    City *currentCity;
    CityConnections cityConnections;

    bool isSolution(std::vector<std::string> path, std::string initialCity);

};


#endif //SERVERUDP_SEARCHPATH_H
