#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int main(int argc, char const *argv[])
{
    FASTIO;

    int n, m;
    while (cin >> n >> m && n != 0 && m != 0)
    {
        vector<int> jack, jill;
        while (n--)
        {
            int cd;
            cin >> cd;
            jack.push_back(cd);
        }
        while (m--)
        {
            int cd;
            cin >> cd;
            jill.push_back(cd);
        }

        vector<int> sell;
        set_intersection(jack.begin(), jack.end(), 
                         jill.begin(),jill.end(),
                         back_inserter(sell));
        
        cout << sell.size() << "\n";
    }
        
    return 0;
}
