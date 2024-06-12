#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, b;
    while (cin >> n >> b)
    {
        if (n == 0 && b == 0) break;

        vector<int> bag;
        int num;
        while (b--)
        {
            cin >> num;
            bag.push_back(num);
        }

        vector<bool> called(n + 1, false);
        for (int n1: bag)
        {
            for (int n2: bag)
                called[abs(n2 - n1)] = true;
        } 

        cout << (all_of(called.begin(), called.end(), [](bool c){ return c; }) ? "Y\n" : "N\n");
    }
    
    return 0;
}
