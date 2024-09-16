#include <iostream>
#include <string>
using namespace std;

int main()
{
    string cmd;
    char type;
    int x;
    int y;
    double k;
    while (cin >> cmd)
    {
        if (cmd == "CREATE")
        {
            cout << "success" << endl;
        }
        else if (cmd == "POINT")
        {
            cin >> type;
            cin >> x;
            cin >> y;
            if (type == 'O')
            {
            }
            else
            {
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
            // Dellocate memory
            return 0;
        }
    }

    return 0;
}