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

//void CityConnections::populateCities()
//{
//    // San Francisco
//    name = SANFRANCISCO;
//    neighbors = {PORTLAND, LAKETAHOE, LOSANGELES};
//    distances = {640, 300, 380};
//    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));
//
//    // Portland
//    name = PORTLAND;
//    neighbors = {SANFRANCISCO, LAKETAHOE, BOISE, SEATLE};
//    distances = {640, 580, 420, 170};
//    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));
//
//    // Seatle
//    name = SEATLE;
//    neighbors = {PORTLAND, BOISE};
//    distances = {170, 500};
//    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));
//
//    // Boise
//    name = BOISE;
//    neighbors = {LAKETAHOE, PORTLAND, SEATLE, YELLOWSTONE};
//    distances = {420, 420, 500, 670};
//    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));
//
//    // Lake Tahoe
//    name = LAKETAHOE;
//    neighbors = {SANFRANCISCO, PORTLAND, BOISE, SALTLAKECITY, PALMSPRINGS};
//    distances = {300, 580, 420, 520, 780};
//    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));
//
//    // Los Angeles
//    name = LOSANGELES;
//    neighbors = {SANFRANCISCO, LASVEGAS, PALMSPRINGS, SANDIEGO};
//    distances = {380, 270, 160, 120};
//    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));
//
//    // San Diego
//    name = SANDIEGO;
//    neighbors = {LOSANGELES, PALMSPRINGS, PHOENIX};
//    distances = {120, 140, 350};
//    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));
//
//    // Palm Spring
//    name = PALMSPRINGS;
//    neighbors = {SANDIEGO, LOSANGELES, LASVEGAS, GRANDCANYON, LAKETAHOE};
//    distances = {140, 160, 290, 440, 780};
//    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));
//
//    // Phoenix
//    name = PHOENIX;
////    neighbors = {SANDIEGO, GRANDCANYON, SALTLAKECITY, ALBUQUERQUE, DALLAS, SANANTONIO};
////    distances = {350, 360, 660, 350, 1070, 990};
//    //test
//    neighbors = {SANDIEGO, GRANDCANYON, SALTLAKECITY, ALBUQUERQUE, DALLAS};
//    distances = {350, 360, 660, 350, 1070};
//    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));
//
//    // Grand Canyon
//    name = GRANDCANYON;
//    neighbors = {LASVEGAS, PALMSPRINGS, PHOENIX};
//    distances = {470, 290, 360};
//    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));
//
//    // Las Vegas
//    name = LASVEGAS;
//    neighbors = {LOSANGELES, PALMSPRINGS, GRANDCANYON, SALTLAKECITY};
//    distances = {270, 290, 470, 420};
//    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));
//
//    // Salt Lake City
//    name = SALTLAKECITY;
//    neighbors = {LAKETAHOE, LASVEGAS, PHOENIX, DENVER};
//    distances = {520, 420, 660, 530};
//    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));
//
//    // Yellowstone
//    name = YELLOWSTONE;
//    //neighbors = {BOISE, DENVER, MINEAPOLIS};
//    //distances = {670, 930, 1340};
//    //test
//    neighbors = {BOISE, DENVER};
//    distances = {670, 930};
//    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));
//
//    // Denver
//    name = DENVER;
////    neighbors = {YELLOWSTONE, SALTLAKECITY, VAIL, ASPEN, COLORADOSPRINGS, OMAHA};
////    distances = {930, 530, 160, 170, 120, 540};
//    // test
//    neighbors = {YELLOWSTONE, SALTLAKECITY, VAIL, ASPEN, COLORADOSPRINGS};
//    distances = {930, 530, 160, 170, 120};
//    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));
//
//    // Vail
//    name = VAIL;
//    neighbors = {DENVER, ASPEN};
//    distances = {160, 80};
//    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));
//
//    // Aspen
//    name = ASPEN;
//    neighbors = {VAIL, DENVER, COLORADOSPRINGS};
//    distances = {80, 170, 180};
//    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));
//
//    // Colorado Springs
//    name = COLORADOSPRINGS;
//    neighbors = {ASPEN, DENVER, DALLAS};
//    distances = {180, 170, 730};
//    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));
//
//    // Albuquerque
//    name = ALBUQUERQUE;
//    neighbors = {PHOENIX};
//    distances = {350};
//    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));
//
//    // Dallas
//    name = DALLAS;
//    neighbors = {PHOENIX, COLORADOSPRINGS};
//    distances = {1070, 730};
//    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));
//
//
//}

void CityConnections::populateCities()
{
    // San Francisco
    name = SANFRANCISCO;
    neighbors = {PORTLAND, LAKETAHOE, LOSANGELES};
    distances = {640,      300,       380};
    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));

    // Portland
    name = PORTLAND;
    neighbors = {SANFRANCISCO, LAKETAHOE, BOISE, SEATLE};
    distances = {640,          580,       420,   170};
    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));

    // Seatle
    name = SEATLE;
    neighbors = {PORTLAND, BOISE};
    distances = {170,      500};
    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));

    // Boise
    name = BOISE;
    neighbors = {LAKETAHOE, PORTLAND, SEATLE, YELLOWSTONE};
    distances = {420,       420,      500,    670};
    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));

    // Lake Tahoe
    name = LAKETAHOE;
    neighbors = {SANFRANCISCO, PORTLAND, BOISE, PALMSPRINGS, SALTLAKECITY};
    distances = {300,          580,      420,   780,         520};
    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));

    // Los Angeles
    name = LOSANGELES;
    neighbors = {SANFRANCISCO, PALMSPRINGS, LASVEGAS};
    distances = {380,          160,         270};
    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));

    // Palm Spring
    name = PALMSPRINGS;
    neighbors = {LOSANGELES, LAKETAHOE, SANDIEGO, LASVEGAS, GRANDCANYON};
    distances = {160,        780,       140,      290,      440};
    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));

    // San Diego
    name = SANDIEGO;
    neighbors = {LOSANGELES, PALMSPRINGS};
    distances = {120,        140};
    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));

    // Las Vegas
    name = LASVEGAS;
    neighbors = {LOSANGELES, PALMSPRINGS, GRANDCANYON, SALTLAKECITY};
    distances = {270,        290,         470,         420};
    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));

    // Grand Canyon
    name = GRANDCANYON;
    neighbors = {LASVEGAS, PALMSPRINGS};
    distances = {470,      440};
    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));

    // Phoenix
    name = PHOENIX;
    neighbors = {SANDIEGO, GRANDCANYON, SALTLAKECITY, ALBUQUERQUE, DALLAS, SANANTONIO};
    distances = {350,      360,         660,          350,         1070,   990};
    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));

    // Salt Lake City
    name = SALTLAKECITY;
    neighbors = {LAKETAHOE, LASVEGAS, PHOENIX, DENVER};
    distances = {520,       420,      660,     530};
    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));

    // Albuquerque
    name = ALBUQUERQUE;
    neighbors = {PHOENIX};
    distances = {350};
    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));

    // Yellowstone
    name = YELLOWSTONE;
    neighbors = {BOISE, DENVER, MINEAPOLIS};
    distances = {670,   930,    1340};
    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));

    // Denver
    name = DENVER;
    neighbors = {YELLOWSTONE, SALTLAKECITY, VAIL, ASPEN, COLORADOSPRINGS, OMAHA};
    distances = {930,         530,          160,  170,   120,             540};
    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));

    // Vail
    name = VAIL;
    neighbors = {DENVER, ASPEN};
    distances = {160,    80};
    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));

    // Aspen
    name = ASPEN;
    neighbors = {VAIL, DENVER, COLORADOSPRINGS};
    distances = {80,   170,    180};
    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));

    // Colorado Springs
    name = COLORADOSPRINGS;
    neighbors = {ASPEN, DENVER, DALLAS};
    distances = {180,   170,    730};
    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));

    // Dallas
    name = DALLAS;
    neighbors = {PHOENIX, COLORADOSPRINGS, SANANTONIO, HOUSTON, KANSASCITY, LITTLEROCK};
    distances = {1070,    730,             280,        250,     550,        320};
    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));

    // San Antonio
    name = SANANTONIO;
    neighbors = {PHOENIX, DALLAS, HOUSTON};
    distances = {990,     280,    310};
    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));

    // Houston
    name = HOUSTON;
    neighbors = {SANANTONIO, DALLAS};
    distances = {310,        250};
    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));

    // Minneapolis
    name = MINEAPOLIS;
    neighbors = {YELLOWSTONE, OMAHA, MILWAUKEE, CHICACO};
    distances = {1340,        380,   340,       410};
    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));

    // Omaha
    name = OMAHA;
    neighbors = {MINEAPOLIS, DENVER, KANSASCITY, CHICACO};
    distances = {380,        540,    190,        470};
    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));

    // Kansas City
    name = KANSASCITY;
    neighbors = {OMAHA, DALLAS, STLOUIS};
    distances = {190,   550,    250};
    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));

    // Milwaukee
    name = MILWAUKEE;
    neighbors = {MINEAPOLIS, CHICACO};
    distances = {340,        90};
    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));

    // Chicago
    name = CHICACO;
    neighbors = {OMAHA, MINEAPOLIS, MILWAUKEE, STLOUIS, INDIANAPOLIS};
    distances = {470,   410,        90,        300,     180};
    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));

    // St Louis
    name = STLOUIS;
    neighbors = {KANSASCITY, CHICACO, LITTLEROCK, MEMPHIS, INDIANAPOLIS};
    distances = {250,        300,     400,        290,     250};
    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));

    // Little Rock
    name = LITTLEROCK;
    neighbors = {STLOUIS, DALLAS, MEMPHIS};
    distances = {400,     320,    140};
    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));

    // Memphis
    name = MEMPHIS;
    neighbors = {STLOUIS, LITTLEROCK, NASHVILLE};
    distances = {290,     140,        210};
    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));

    // Indianapolis
    name = INDIANAPOLIS;
    neighbors = {CHICACO, STLOUIS, NASHVILLE};
    distances = {180,     250,     290};
    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));

    // Nashville
    name = NASHVILLE;
    neighbors = {INDIANAPOLIS, MEMPHIS};
    distances = {290,          210};
    cities.insert(std::pair<std::string, City>(name, City(name, neighbors, distances)));

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