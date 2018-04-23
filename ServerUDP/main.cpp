#include <iostream>
#include "Server.h"

using namespace std;

int main()
{

    try
    {
        Server server; // start the server
    } catch (std::invalid_argument &ex)
    {
        cout << "Error " << ex.what() << endl;
    }






    return 0;
}