#include <iostream>
#include <string>
using namespace std;

#include "Grid.h"

int main()
{
    string cmd;
    char type;
    int x, y = 0;
    double k;
    Grid *map = nullptr;

    while (cin >> cmd)
    {
        if (cmd == "CREATE")
        {
            cin >> x;
            cin >> y;
            if (map)
            {
                delete map;
            }
            map = new Grid(x, y);
            cout << "success" << endl;
        }
        else if (cmd == "POINT")
        {
            cin >> type;
            cin >> x;
            cin >> y;
            if (map->isValid(x, y))
            {
                map->setObject(x, y, type);
            }
            else
            {
                cout << "failure" << endl;
            }

            cout << "success" << endl;
        }
        else if (cmd == "MOVE")
        {
            cin >> x;
            cin >> y;
        }
        else if (cmd == "CLEAR")
        {
        }
        else if (cmd == "UPDATE")
        {
            cin >> k;
            if (k > 0)
            {
                cout << "success" << endl;
            }
            else
            {
                cout << "failure" << endl;
            }
        }
        else if (cmd == "EXIT")
        {
            if (map)
            {
                delete map;
                map = nullptr;
            }
            return 0;
        }
    }

    if (map)
    {
        delete map;
        map = nullptr;
    }
    return 0;
}