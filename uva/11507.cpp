#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    int wirelen;
    for (;;)
    {
        cin >> wirelen;
        if (wirelen == 0) break;

        string dlast = "+x";
        string op;
        for (int i = 0; i < wirelen - 1; ++i)
        {   
            cin >> op;
            if (op == "No")
                continue;
            if (op == "+y")
            {
                if      (dlast == "+x") dlast = "+y";
                else if (dlast == "-x") dlast = "-y";
                else if (dlast == "+y") dlast = "-x";
                else if (dlast == "-y") dlast = "+x";
            }
            else if (op == "-y")
            {
                if      (dlast == "+x") dlast = "-y";
                else if (dlast == "-x") dlast = "+y";
                else if (dlast == "+y") dlast = "+x";
                else if (dlast == "-y") dlast = "-x";
            }
            else if (op == "+z")
            {
                if      (dlast == "+x") dlast = "+z";
                else if (dlast == "-x") dlast = "-z";
                else if (dlast == "+z") dlast = "-x";
                else if (dlast == "-z") dlast = "+x";
            }
            else if (op == "-z")
            {
                if      (dlast == "+x") dlast = "-z";
                else if (dlast == "-x") dlast = "+z";
                else if (dlast == "+z") dlast = "+x";
                else if (dlast == "-z") dlast = "-x";
            }
        }
        cout << dlast << "\n";
    }
    
    return 0;
}
