#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int main(int argc, char const *argv[])
{
    FASTIO;

    int n;
    while (cin >> n)
    {
        vector<int> seq;
        int num;
        while (n--) 
        {
            cin >> num;
            seq.push_back(num);
        }

        vector<bool> check(seq.size(), false);
        check[0] = true;
        for (auto it = seq.begin() + 1; it != seq.end(); ++it)
            check[abs(*it - *prev(it))] = true;

        if (all_of(check.begin(), check.end(), [](bool c){ return c; }))
            cout << "Jolly\n";
        else 
            cout << "Not jolly\n";
    }
    
    return 0;
}

