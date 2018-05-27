//
// Created by Gustavo Brunetto on 29/04/18.
//

#ifndef SERVERUDP_CITYCONNECTIONS_H
#define SERVERUDP_CITYCONNECTIONS_H


#include <string>
#include <vector>
#include <map>
#include "City.h"

#define SANFRANCISCO "San Francisco"
#define LOSANGELES "Los Angeles"
#define SANDIEGO "San Diego"
#define PALMSPRINGS "Palm Springs"
#define GRANDCANYON "Grand Canyon"
#define LASVEGAS "Las Vegas"
#define PHOENIX "Phoenix"
#define ALBUQUERQUE "Albuquerque"
#define LAKETAHOE "Lake Tahoe"
#define PORTLAND "Portland"
#define SEATLE "Seatle"
#define BOISE "Boise"
#define YELLOWSTONE "Yellowstone"
#define SALTLAKECITY "Salt Lake City"
#define VAIL "Vail"
#define ASPEN "Aspen"
#define DENVER "Denver"
#define COLORADOSPRINGS "Colorado Springs"
#define SANANTONIO "San Antonio"
#define DALLAS "Dallas"
#define HOUSTON "Houston"
#define KANSASCITY "Kansas City"
#define OMAHA "Omaha"
#define MINEAPOLIS "Mineapolis"
#define NOVAORLEANS "Nova Orleans"
#define LITTLEROCK "Little Rock"
#define MEMPHIS "Memphis"
#define STLOUIS "St Louis"
#define CHICACO "Chicago"
#define MILWAUKEE "Milwaukee"
#define MIAMI "Miami"
#define FORTLAUNDERDALE "Fort Launderdale"
#define ORLANDO "Orlando"
#define ATLANTA "Atlanta"
#define NASHVILLE "Nashville"
#define INDIANAPOLIS "Indianapolis"
#define DETROIT "Detroit"
#define RICHMOND "Richmond"
#define WASHINGTON "Washington"
#define NOVAYORK "Nova York"
#define BOSTON "Boston"
#define ALBANY "Albany"

class CityConnections
{
public:
    CityConnections();

    std::map<std::string, City> getCities();

    std::vector<City> getCitiesVector();

    std::vector<std::string> getCitiesName();

    City getCity(std::string city);

    std::vector<std::string> getNeighbors(std::string city);

    int getNumberOfCities();


private:
    std::vector<std::string> citiesName;
    std::vector<City> city;
    std::string name;
    std::vector<std::string> neighbors;
    std::vector<double> distances;
    std::map<std::string, City> cities;
    int numberOfCities;


    void populateCities();
};


#endif //SERVERUDP_CITYCONNECTIONS_H
