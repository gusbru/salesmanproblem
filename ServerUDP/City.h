//
// Created by Gustavo Brunetto on 09/05/18.
//

#ifndef SERVERUDP_CITY_H
#define SERVERUDP_CITY_H

#include <string>
#include <vector>
#include <map>

class City
{
public:
    City() = default;

    City(std::string name, std::string region, std::vector<std::string> neighborsName,
         std::vector<double> neighborsDistance);

    std::string getName();

    int getNumNeighbors();

    std::vector<std::string> getNeighborsName();

    double getNeighborDistance(std::string neighborName);

    void getKeys();

    bool isVisited();

    void setVisited();

    std::string getRegion();

    void setBorder();

    bool isBorder();

private:
    std::string name;
    std::map<std::string, double> neighbors;
    std::string region;
    bool visited{};
    bool border = false;
};


#endif //SERVERUDP_CITY_H
