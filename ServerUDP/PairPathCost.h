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
    PairPathCost() = default;
    PairPathCost(std::vector<std::string> path);
    PairPathCost(std::vector<std::string> path, double cost);
    std::vector<std::string> getPath();
    double getCost();
    std::string toString();
private:
    std::vector<std::string> path;
    double cost = 0;
};


#endif //SERVERUDP_PAIRPATHCOST_H
