//
// Created by Gustavo Brunetto on 29/04/18.
//

#include <iostream>
#include "CityConnections.h"

CityConnections::CityConnections()
{
    populateCities();
}

std::vector<City> CityConnections::getCitiesVector()
{
    for (auto &c : cities)
        city.emplace_back(c.second);

    return this->city;
}

std::map<std::string, City> CityConnections::getCities()
{
    return this->cities;
}

void CityConnections::populateCities()
{
    // San Francisco
    name = SANFRANCISCO;
    region = "west";
    neighbors = {PORTLAND, LAKETAHOE, LOSANGELES};
    distances = {640,      300,       380};
    cities.insert(std::pair<std::string, City>(name, City(name, region, neighbors, distances)));

    // Portland
    name = PORTLAND;
    region = "west";
    neighbors = {SANFRANCISCO, LAKETAHOE, BOISE, SEATLE};
    distances = {640,          580,       420,   170};
    cities.insert(std::pair<std::string, City>(name, City(name, region, neighbors, distances)));

    // Seatle
    name = SEATLE;
    region = "west";
    neighbors = {PORTLAND, BOISE};
    distances = {170,      500};
    cities.insert(std::pair<std::string, City>(name, City(name, region, neighbors, distances)));

    // Boise
    name = BOISE;
    region = "west";
    neighbors = {LAKETAHOE, PORTLAND, SEATLE, YELLOWSTONE};
    distances = {420,       420,      500,    670};
    cities.insert(std::pair<std::string, City>(name, City(name, region, neighbors, distances)));

    // Lake Tahoe
    name = LAKETAHOE;
    region = "west";
    neighbors = {SANFRANCISCO, PORTLAND, BOISE, PALMSPRINGS, SALTLAKECITY};
    distances = {300,          580,      420,   780,         520};
    cities.insert(std::pair<std::string, City>(name, City(name, region, neighbors, distances)));

    // Los Angeles
    name = LOSANGELES;
    region = "west";
    neighbors = {SANFRANCISCO, PALMSPRINGS, LASVEGAS, SANDIEGO};
    distances = {380,          160,         270,      120};
    cities.insert(std::pair<std::string, City>(name, City(name, region, neighbors, distances)));

    // Palm Spring
    name = PALMSPRINGS;
    region = "west";
    neighbors = {LOSANGELES, LAKETAHOE, SANDIEGO, LASVEGAS, GRANDCANYON};
    distances = {160,        780,       140,      290,      440};
    cities.insert(std::pair<std::string, City>(name, City(name, region, neighbors, distances)));

    // San Diego
    name = SANDIEGO;
    region = "west";
    neighbors = {LOSANGELES, PALMSPRINGS};
    distances = {120,        140};
    cities.insert(std::pair<std::string, City>(name, City(name, region, neighbors, distances)));

    // Las Vegas
    name = LASVEGAS;
    region = "west";
    neighbors = {LOSANGELES, PALMSPRINGS, GRANDCANYON, SALTLAKECITY};
    distances = {270,        290,         470,         420};
    cities.insert(std::pair<std::string, City>(name, City(name, region, neighbors, distances)));

    // Grand Canyon
    name = GRANDCANYON;
    region = "west";
    neighbors = {LASVEGAS, PALMSPRINGS, PHOENIX};
    distances = {470,      440,         360};
    cities.insert(std::pair<std::string, City>(name, City(name, region, neighbors, distances)));

    // Phoenix
    name = PHOENIX;
    region = "west";
    neighbors = {SANDIEGO, GRANDCANYON, SALTLAKECITY, ALBUQUERQUE, DALLAS, SANANTONIO};
    distances = {350,      360,         660,          350,         1070,   990};
    cities.insert(std::pair<std::string, City>(name, City(name, region, neighbors, distances)));

    // Salt Lake City
    name = SALTLAKECITY;
    region = "west";
    neighbors = {LAKETAHOE, LASVEGAS, PHOENIX, DENVER};
    distances = {520,       420,      660,     530};
    cities.insert(std::pair<std::string, City>(name, City(name, region, neighbors, distances)));

    // Albuquerque
    name = ALBUQUERQUE;
    region = "west";
    neighbors = {PHOENIX};
    distances = {350};
    cities.insert(std::pair<std::string, City>(name, City(name, region, neighbors, distances)));

    // Yellowstone
    name = YELLOWSTONE;
    region = "west";
    neighbors = {BOISE, DENVER, MINEAPOLIS};
    distances = {670,   930,    1340};
    cities.insert(std::pair<std::string, City>(name, City(name, region, neighbors, distances)));

    // Denver
    name = DENVER;
    region = "west";
    neighbors = {YELLOWSTONE, SALTLAKECITY, VAIL, ASPEN, COLORADOSPRINGS, OMAHA};
    distances = {930,         530,          160,  170,   120,             540};
    cities.insert(std::pair<std::string, City>(name, City(name, region, neighbors, distances)));

    // Vail
    name = VAIL;
    region = "west";
    neighbors = {DENVER, ASPEN};
    distances = {160,    80};
    cities.insert(std::pair<std::string, City>(name, City(name, region, neighbors, distances)));

    // Aspen
    name = ASPEN;
    region = "west";
    neighbors = {VAIL, DENVER, COLORADOSPRINGS};
    distances = {80,   170,    180};
    cities.insert(std::pair<std::string, City>(name, City(name, region, neighbors, distances)));

    // Colorado Springs
    name = COLORADOSPRINGS;
    region = "west";
    neighbors = {ASPEN, DENVER, DALLAS};
    distances = {180,   170,    730};
    cities.insert(std::pair<std::string, City>(name, City(name, region, neighbors, distances)));

    // Dallas
    name = DALLAS;
    region = "west";
    neighbors = {PHOENIX, COLORADOSPRINGS, SANANTONIO, HOUSTON, KANSASCITY, LITTLEROCK, ATLANTA};
    distances = {1070,    730,             280,        250,     550,        320,        790};
    cities.insert(std::pair<std::string, City>(name, City(name, region, neighbors, distances)));

    // San Antonio
    name = SANANTONIO;
    region = "west";
    neighbors = {PHOENIX, DALLAS, HOUSTON};
    distances = {990,     280,    310};
    cities.insert(std::pair<std::string, City>(name, City(name, region, neighbors, distances)));

    // Houston
    name = HOUSTON;
    region = "west";
    neighbors = {SANANTONIO, DALLAS, NOVAORLEANS};
    distances = {310,        250,    530};
    cities.insert(std::pair<std::string, City>(name, City(name, region, neighbors, distances)));

    // Minneapolis
    name = MINEAPOLIS;
    region = "east";
    neighbors = {YELLOWSTONE, OMAHA, MILWAUKEE, CHICACO};
    distances = {1340,        380,   340,       410};
    cities.insert(std::pair<std::string, City>(name, City(name, region, neighbors, distances)));

    // Omaha
    name = OMAHA;
    region = "east";
    neighbors = {MINEAPOLIS, DENVER, KANSASCITY, CHICACO};
    distances = {380,        540,    190,        470};
    cities.insert(std::pair<std::string, City>(name, City(name, region, neighbors, distances)));

    // Kansas City
    name = KANSASCITY;
    region = "east";
    neighbors = {OMAHA, DALLAS, STLOUIS};
    distances = {190,   550,    250};
    cities.insert(std::pair<std::string, City>(name, City(name, region, neighbors, distances)));

    // Milwaukee
    name = MILWAUKEE;
    region = "east";
    neighbors = {MINEAPOLIS, CHICACO};
    distances = {340,        90};
    cities.insert(std::pair<std::string, City>(name, City(name, region, neighbors, distances)));

    // Chicago
    name = CHICACO;
    region = "east";
    neighbors = {WASHINGTON, OMAHA, MINEAPOLIS, STLOUIS, INDIANAPOLIS, DETROIT, MILWAUKEE};
    distances = {700,        470,   410,        300,     180,          280,     90};
    cities.insert(std::pair<std::string, City>(name, City(name, region, neighbors, distances)));

    // St Louis
    name = STLOUIS;
    region = "east";
    neighbors = {KANSASCITY, CHICACO, LITTLEROCK, MEMPHIS, INDIANAPOLIS};
    distances = {250,        300,     400,        290,     250};
    cities.insert(std::pair<std::string, City>(name, City(name, region, neighbors, distances)));

    // Little Rock
    name = LITTLEROCK;
    region = "east";
    neighbors = {STLOUIS, DALLAS, MEMPHIS};
    distances = {400,     320,    140};
    cities.insert(std::pair<std::string, City>(name, City(name, region, neighbors, distances)));

    // Memphis
    name = MEMPHIS;
    region = "east";
    neighbors = {STLOUIS, LITTLEROCK, NASHVILLE, ATLANTA};
    distances = {290,     140,        210,       390};
    cities.insert(std::pair<std::string, City>(name, City(name, region, neighbors, distances)));

    // Indianapolis
    name = INDIANAPOLIS;
    region = "east";
    neighbors = {CHICACO, STLOUIS, NASHVILLE, WASHINGTON};
    distances = {180,     250,     290,       590};
    cities.insert(std::pair<std::string, City>(name, City(name, region, neighbors, distances)));

    // Nashville
    name = NASHVILLE;
    region = "east";
    neighbors = {RICHMOND, INDIANAPOLIS, MEMPHIS, ATLANTA};
    distances = {710,      290,          210,     240};
    cities.insert(std::pair<std::string, City>(name, City(name, region, neighbors, distances)));

    // Atlanta
    name = ATLANTA;
    region = "east";
    neighbors = {RICHMOND, NASHVILLE, MEMPHIS, DALLAS, NOVAORLEANS, ORLANDO};
    distances = {560,      240,       390,     790,    470,         440};
    cities.insert(std::pair<std::string, City>(name, City(name, region, neighbors, distances)));

    // Nova Orleans
    name = NOVAORLEANS;
    region = "east";
    neighbors = {HOUSTON, ATLANTA, NOVAORLEANS, MIAMI};
    distances = {530,     470,     640,         860};
    cities.insert(std::pair<std::string, City>(name, City(name, region, neighbors, distances)));

    // Orlando
    name = ORLANDO;
    neighbors = {NOVAORLEANS, ATLANTA, FORTLAUNDERDALE, MIAMI};
    distances = {640,         440,     180,             230};
    cities.insert(std::pair<std::string, City>(name, City(name, region, neighbors, distances)));

    // Fort Lauderdale
    name = FORTLAUNDERDALE;
    region = "east";
    neighbors = {ORLANDO, MIAMI};
    distances = {180,     30};
    cities.insert(std::pair<std::string, City>(name, City(name, region, neighbors, distances)));

    // Miami
    name = MIAMI;
    region = "east";
    neighbors = {NOVAORLEANS, ORLANDO, FORTLAUNDERDALE};
    distances = {860,         230,     30};
    cities.insert(std::pair<std::string, City>(name, City(name, region, neighbors, distances)));

    // Washington
    name = WASHINGTON;
    region = "east";
    neighbors = {CHICACO, INDIANAPOLIS, DETROIT, RICHMOND, NOVAYORK};
    distances = {700,     590,          530,     200,      240};
    cities.insert(std::pair<std::string, City>(name, City(name, region, neighbors, distances)));

    // Richmond
    name = RICHMOND;
    region = "east";
    neighbors = {NASHVILLE, ATLANTA, WASHINGTON};
    distances = {710,       560,     200};
    cities.insert(std::pair<std::string, City>(name, City(name, region, neighbors, distances)));

    // Detroit
    name = DETROIT;
    region = "east";
    neighbors = {WASHINGTON, CHICACO, ALBANY, NOVAYORK};
    distances = {530,        280,     650,    640};
    cities.insert(std::pair<std::string, City>(name, City(name, region, neighbors, distances)));

    // Albany
    name = ALBANY;
    region = "east";
    neighbors = {DETROIT, NOVAYORK, BOSTON};
    distances = {650,     150,      170};
    cities.insert(std::pair<std::string, City>(name, City(name, region, neighbors, distances)));

    // Nova York
    name = NOVAYORK;
    region = "east";
    neighbors = {WASHINGTON, DETROIT, ALBANY, BOSTON};
    distances = {240,        640,     150,    210};
    cities.insert(std::pair<std::string, City>(name, City(name, region, neighbors, distances)));

    // Boston
    name = BOSTON;
    region = "east";
    neighbors = {ALBANY, NOVAYORK};
    distances = {170,    210};
    cities.insert(std::pair<std::string, City>(name, City(name, region, neighbors, distances)));

    // set the borders
    std::vector<std::string> cityBorder = {YELLOWSTONE, DENVER, DALLAS, HOUSTON, NOVAORLEANS,
                                           LITTLEROCK, ATLANTA, KANSASCITY, OMAHA, MINEAPOLIS};

    for (auto &c : cityBorder)
        cities.at(c).setBorder();

}

City CityConnections::getCity(std::string city)
{
    return cities.at(city);
}

std::vector<std::string> CityConnections::getCitiesName()
{
    std::vector<std::string> citiesName;
    for (auto &c : cities)
    {
        citiesName.emplace_back(c.first);
    }
    return citiesName;
}

std::vector<std::string> CityConnections::getNeighbors(std::string city)
{
    City currentCity = cities.at(city);
    return currentCity.getNeighborsName();
}

int CityConnections::getNumberOfCities()
{
    return (int) cities.size();
}