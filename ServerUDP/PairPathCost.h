//
// Created by Gustavo Brunetto on 19/05/18.
//

#ifndef SERVERUDP_PAIRPATHCOST_H
#define SERVERUDP_PAIRPATHCOST_H

#include <string>
#include <vector>
#include "City.h"

class PairPathCost
{
public:
    PairPathCost(std::map<std::string, City> cities);

    PairPathCost(const PairPathCost &model);

    std::vector<std::string> getPath();

    double getCost();

    std::string toString();

    void addCity(City city, double cost);

    City getCity(std::string cityName);

    int getNumberOfVisitedCities();

private:
    std::vector<std::string> path{};
    std::map<std::string, City> cities;
    double cost = 0;
};


#endif //SERVERUDP_PAIRPATHCOST_H
