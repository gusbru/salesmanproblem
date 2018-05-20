#include <iostream>
#include "Server.h"
#include "SearchPath.h"

using namespace std;

int main()
{

    try
    {
//        Server server; // start the server

        SearchPath searchPath("San Francisco");
        searchPath.start();






    } catch (std::invalid_argument &ex)
    {
        cout << "Error " << ex.what() << endl;
    }






    return 0;
}