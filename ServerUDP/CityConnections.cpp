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
    name = SANFRANCISCO;
    neighbors = {PORTLAND, LAKETAHOE, LOSANGELES};
    distances = {640, 300, 380};
    cities.insert(std::pair <std::string, City> (name, City(name, neighbors, distances)));

    // Portland
    name = PORTLAND;
    neighbors = {SANFRANCISCO, LAKETAHOE, BOISE, SEATLE};
    distances = {640, 580, 420, 170};
    cities.insert(std::pair <std::string, City> (name, City(name, neighbors, distances)));

    // Seatle
    name = SEATLE;
    neighbors = {PORTLAND, BOISE};
    distances = {170, 500};
    cities.insert(std::pair <std::string, City> (name, City(name, neighbors, distances)));

    // Boise
    name = BOISE;
    neighbors = {LAKETAHOE, PORTLAND, SEATLE, YELLOWSTONE};
    distances = {420, 420, 500, 670};
    cities.insert(std::pair <std::string, City> (name, City(name, neighbors, distances)));

    // Lake Tahoe
    name = LAKETAHOE;
    neighbors = {SANFRANCISCO, PORTLAND, BOISE, SALTLAKECITY, PALMSPRINGS};
    distances = {300, 580, 420, 520, 780};
    cities.insert(std::pair <std::string, City> (name, City(name, neighbors, distances)));

    // Los Angeles
    name = LOSANGELES;
    neighbors = {SANFRANCISCO, LASVEGAS, PALMSPRINGS, SANDIEGO};
    distances = {380, 270, 160, 120};
    cities.insert(std::pair <std::string, City> (name, City(name, neighbors, distances)));

    // San Diego
    name = SANDIEGO;
    neighbors = {LOSANGELES, PALMSPRINGS, PHOENIX};
    distances = {120, 140, 350};
    cities.insert(std::pair <std::string, City> (name, City(name, neighbors, distances)));

    // Palm Spring
    name = PALMSPRINGS;
    neighbors = {SANDIEGO, LOSANGELES, LASVEGAS, GRANDCANYON, LAKETAHOE};
    distances = {140, 160, 290, 440, 780};
    cities.insert(std::pair <std::string, City> (name, City(name, neighbors, distances)));

    // Phoenix
    name = PHOENIX;
    neighbors = {SANDIEGO, GRANDCANYON, SALTLAKECITY, ALBUQUERQUE, DALLAS, SANANTONIO};
    distances = {350, 360, 660, 350, 1070, 990};
    cities.insert(std::pair <std::string, City> (name, City(name, neighbors, distances)));

    // Grand Canyon
    name = GRANDCANYON;
    neighbors = {LASVEGAS, PALMSPRINGS, PHOENIX};
    distances = {470, 290, 360};
    cities.insert(std::pair <std::string, City> (name, City(name, neighbors, distances)));

    // Las Vegas
    name = LASVEGAS;
    neighbors = {LOSANGELES, PALMSPRINGS, GRANDCANYON, SALTLAKECITY};
    distances = {270, 290, 470, 420};
    cities.insert(std::pair <std::string, City> (name, City(name, neighbors, distances)));

    // Salt Lake City
    name = SALTLAKECITY;
    neighbors = {LAKETAHOE, LASVEGAS, PHOENIX, DENVER};
    distances = {520, 420, 660, 530};
    cities.insert(std::pair <std::string, City> (name, City(name, neighbors, distances)));


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