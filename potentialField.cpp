#include <iostream>
#include <string>
using namespace std;

#include "Grid.h"

int main()
{
    string cmd;
    char type;
    int x, y = 0;
    double k, potential;
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
            if (map && map->isValid(x, y))
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
            if (map && map->isValid(x, y))
            {
                potential = map->move(x, y);
                cout << potential << " " << potential << endl;
            }
            else
            {
                cout << "failure" << endl;
            }
        }
        else if (cmd == "CLEAR")
        {
            if (map)
            {
                map->clear();
                cout << "success" << endl;
            }
            else
            {
                cout << "failure" << endl;
            }
        }
        else if (cmd == "UPDATE")
        {
            cin >> k;
            if (k > 0 && map)
            {
                map->updateK(k);
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