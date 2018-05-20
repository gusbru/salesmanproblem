//
// Created by Gustavo Brunetto on 29/04/18.
//

#include <iostream>
#include "CityConnections.h"

CityConnections::CityConnections()
{
    populateCities();
}

std::vector<City> *CityConnections::getCities()
{
    for (auto &c : cities)
        city.emplace_back(c.second);

    return &this->city;
}

void CityConnections::populateCities()
{
    // San Francisco
    neighbors = {PORTLAND, LAKETAHOE, LOSANGELES};
    distances = {640, 300, 380};
    cities.insert(std::pair <std::string, City> (SANFRANCISCO, City(SANFRANCISCO, neighbors, distances)));

    // Portland
    neighbors = {SANFRANCISCO, LAKETAHOE, BOISE, SEATLE};
    distances = {640, 580, 420, 170};
    cities.insert(std::pair <std::string, City> (PORTLAND, City(PORTLAND, neighbors, distances)));

    // Seatle
    neighbors = {PORTLAND, BOISE};
    distances = {170, 500};
    cities.insert(std::pair <std::string, City> (SEATLE, City(SEATLE, neighbors, distances)));

    // Boise
    neighbors = {LAKETAHOE, PORTLAND, SEATLE, YELLOWSTONE};
    distances = {420, 420, 500, 670};
    cities.insert(std::pair <std::string, City> (BOISE, City(BOISE, neighbors, distances)));

    // Lake Tahoe
    neighbors = {SANFRANCISCO, PORTLAND, BOISE, SALTLAKECITY, PALMSPRINGS};
    distances = {300, 580, 420, 520, 780};
    cities.insert(std::pair <std::string, City> (LAKETAHOE, City(LAKETAHOE, neighbors, distances)));

    // Los Angeles
    neighbors = {SANFRANCISCO, LASVEGAS, PALMSPRINGS, SANDIEGO};
    distances = {380, 270, 160, 120};
    cities.insert(std::pair <std::string, City> (LOSANGELES, City(LOSANGELES, neighbors, distances)));

    // San Diego
    neighbors = {LOSANGELES, PALMSPRINGS, PHOENIX};
    distances = {120, 140, 350};
    cities.insert(std::pair <std::string, City> (SANDIEGO, City(SANDIEGO, neighbors, distances)));

    // Palm Spring
    neighbors = {SANDIEGO, LOSANGELES, LASVEGAS, GRANDCANYON, LAKETAHOE};
    distances = {140, 160, 290, 440, 780};
    cities.insert(std::pair <std::string, City> (PALMSPRINGS, City(PALMSPRINGS, neighbors, distances)));
}

City *CityConnections::getCity(std::string city)
{
    return &cities.at(city);
}

std::vector<std::string> CityConnections::getCitiesName()
{
    for (auto &c : cities ) {
        citiesName.emplace_back(c.first);
    }
    return citiesName;
}


//    city = {SANFRANCISCO,
//            LOSANGELES,
//            SANDIEGO,
//            PALMSPRINGS,
//            GRANDCANYON,
//            LASVEGAS,
//            PHOENIX,
//            ALBUQUERQUE,
//            LAKETAHOE,
//            PORTLAND,
//            SEATLE,
//            BOISE,
//            YELLOWSTONE,
//            SALTLAKECITY,
//            VAIL,
//            ASPEN,
//            DENVER,
//            COLORADOSPRINGS,
//            SANANTONIO,
//            DALLAS,
//            HOUSTON,
//            KANSASCITY,
//            OMAHA,
//            MINEAPOLIS,
//            NOVAORLEANS,
//            LITTLEROCK,
//            MEMPHIS,
//            STLOUIS,
//            CHICACO,
//            MILWAUKEE,
//            MIAMI,
//            FORTLAUNDERDALE,
//            ORLANDO,
//            ATLANTA,
//            NASHVILLE,
//            INDIANAPOLIS,
//            DETROIT,
//            RICHMOND,
//            WASHINGTON,
//            NOVAYORK,
//            BOSTON,
//            ALBANY};