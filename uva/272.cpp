#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    int id = 0;
    string line;
    while (getline(cin >> ws, line))
    {
        for(;;)
        {
            auto f = line.find('"');
            if (f == string::npos)
                break;
            if (id % 2 == 0)
            {
                line[f] = '`';
                line.insert(line.begin() + f, '`');
            }
            else
            {
                line[f] = '\'';
                line.insert(line.begin() + f, '\'');
            }
            ++id;
        }
        cout << line << "\n";
    }
    return 0;
}

