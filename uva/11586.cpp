#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
using vs = vector<string>;
#define ALL(x) x.begin(), x.end()

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;

    while (t--)
    {
        string line, piece;
        vs vpiece;    
        while (getline(cin >> ws, line))
        {
            stringstream ss{ line };
            int numMF = 0;
            while (ss >> piece) 
            {
                if (piece == "MF" || piece == "FM") 
                {
                    ++numMF;
                    continue;
                }
                vpiece.push_back(piece);
            }
            auto numFF = count_if(ALL(vpiece), [](const string& p){ return p == "FF"; });   
            auto numMM = count_if(ALL(vpiece), [](const string& p){ return p == "MM"; });
            
            if (vpiece.size() == 0 && numMF == 1)
                cout << "NO LOOP\n";
            else if (numFF == numMM)
                cout << "LOOP\n";
            else 
                cout << "NO LOOP\n";
            vpiece.clear();
        }
    }
    return 0;
}
