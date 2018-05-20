//
// Created by Gustavo Brunetto on 09/05/18.
//

#include <iostream>
#include "City.h"

City::City(std::string name,
           std::vector<std::string> neighborsName,
           std::vector<double> neighborsDistance) {
    this->name = name;
    this->visited = false;
    for (int i=0; i < neighborsName.size(); i++)
        neighbors.insert(std::pair<std::string, double> (neighborsName[i], neighborsDistance[i]));
}

std::string City::getName() {
    return this->name;
}

unsigned long City::getNumNeighbors() {
    return this->neighbors.size();
}

std::vector<std::string> City::getNeighborsName() {
    std::vector<std::string> neighborsName;
    for (auto &c : neighbors)
        neighborsName.emplace_back(c.first);
    return neighborsName;
}

double City::getDistance(std::string neighborName) {
    return neighbors.at(neighborName);
}

void City::printKeys()
{
    for (auto &neighbor : neighbors)
        std::cout << neighbor.first << std::endl;
}

bool City::isVisited()
{
    return this->visited;
}

void City::setVisited()
{
    this->visited = true;
}

