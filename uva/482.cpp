#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

int main(int argc, char const *argv[])
{
    int t, id = 1;;
    cin >> t;
    while (t--)
    {
        string line;
        getline(cin >> ws, line);
        stringstream ss{ line };

        vector<int> permuted;
        int num;
        while (ss >> num)
            permuted.push_back(num);

        map<int, string> map_arr;
        for(int i: permuted)
        {
            string str;
            cin >> str;
            map_arr[i] = str;
        }

        if (id++ > 1)
            cout << "\n";
        for (const auto& p: map_arr)
            cout << p.second << "\n";
    }
    
    return 0;
}
