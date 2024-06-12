#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
using ll = long long;
int main(int argc, char const *argv[])
{
    FASTIO;

    int n, id = 1;
    while (cin >> n && n != 0)
    {
        vector<int> numset;
        while (n--)
        {
            int num;
            cin >> num;
            numset.push_back(num);
        }
        
        int m;
        cin >> m;

        cout << "Case " << id++ << ":\n";
        while (m--)
        {
            int q;
            cin >> q;
            int mindiff = INT_MAX, closest;
            for (int i = 0; i < numset.size(); ++i)
            {
                for (int j = i + 1; j < numset.size(); ++j)
                {
                    int diff = abs(numset[i] + numset[j] - q);
                    if (diff < mindiff)
                    {
                        mindiff = diff;
                        closest = numset[i] + numset[j];
                    }
                }
            }
            cout << "Closest sum to " << q << " is " << closest << ".\n";
        }
        
        
    }
    
    return 0;
}
