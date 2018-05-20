//
// Created by Gustavo Brunetto on 19/05/18.
//

#include "PairPathCost.h"

PairPathCost::PairPathCost(std::vector<std::string> path)
{
    this->path = path;
}

PairPathCost::PairPathCost(std::vector<std::string> path, double cost)
{
    this->path = path;
    this->cost = cost;
}

std::vector<std::string> PairPathCost::getPath()
{
    return this->path;
}

double PairPathCost::getCost()
{
    return this->cost;
}

std::string PairPathCost::toString()
{
    std::string ret;
    for (auto &item : path)
    {
        ret += item + "|";
    }
    ret += " (" + std::to_string(cost) + ")";

    return ret;
}




