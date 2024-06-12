#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        string ins;
        vector<string> hist;
        int p = 0;
        while (n--)
        {
            getline(cin >> ws, ins);
        
            if (ins[0] == 'S')
            {
                string s1, s2;
                int oins;
                stringstream ss{ ins };
                ss >> s1 >> s2 >> oins; 
                ins = hist[oins - 1];
            }
            hist.push_back(ins);
            if (ins[0] == 'L') --p;
            else if (ins[0] == 'R') ++p;
        }
        cout << p << "\n";
    }

    return 0;
}
