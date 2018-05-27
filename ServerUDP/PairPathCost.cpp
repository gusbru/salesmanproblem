//
// Created by Gustavo Brunetto on 19/05/18.
//

#include "PairPathCost.h"

PairPathCost::PairPathCost(std::map<std::string, City> cities)
{
    this->cities = cities;
    this->path   = {};
    this->cost   = 0.0;
}

PairPathCost::PairPathCost(const PairPathCost &model)
{
    this->cities = model.cities;
    this->path   = model.path;
    this->cost   = model.cost;
}

double PairPathCost::getCost()
{
    return this->cost;
}

std::string PairPathCost::toString()
{
    std::string ret;
    for (auto &item : cities)
    {
        ret += item.second.getName() + "|";
    }
    ret += " (" + std::to_string(cost) + ")";

    return ret;
}

void PairPathCost::addCity(City city, double cost)
{
    path.emplace_back(city.getName());
    this->cost += cost;
    cities.at(city.getName()).setVisited();
}

int PairPathCost::getNumberOfVisitedCities()
{
    return (int) path.size();
}

std::vector<std::string> PairPathCost::getPath()
{
    return path;
}

City PairPathCost::getCity(std::string cityName)
{
    return cities.at(cityName);
}




