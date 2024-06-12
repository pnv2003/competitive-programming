#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int main(int argc, char const *argv[])
{
    int id = 1;
    string line;
    while (getline(cin >> ws, line))
    {
        if (line == "end") break;
        
        vector<stack<char>> contstacks;
        for (char cont: line)
        {
            int pos = -1;
            int mindiff = 'Z' - 'A';
            for (int i = 0; i < contstacks.size(); ++i)
            {
                int diff = contstacks[i].top() - cont;
                if (diff >= 0 && diff < mindiff)
                {
                    pos = i;
                    mindiff = diff;
                }
            }

            if (pos == -1)
            {
                stack<char> s;
                s.push(cont);
                contstacks.push_back(s);
            }
            else
                contstacks[pos].push(cont);
        }

        cout << "Case " << id++ << ": " << contstacks.size() << "\n";
    }
    
    return 0;
}
