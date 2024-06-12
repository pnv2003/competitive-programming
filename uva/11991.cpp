#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int main(int argc, char const *argv[])
{
    FASTIO;
    int n, m;
    while (cin >> n >> m)
    {
        unordered_map<int, vector<int>> index;
        
        for (int i = 0; i < n; ++i)
        {
            int num;
            cin >> num;
            if (index.count(num) == 0)
                index[num] = vector<int>();
            index[num].push_back(i + 1);
        }

        while (m--)
        {
            int k, v;
            cin >> k >> v;
            if (k - 1 >= index[v].size())
                cout << "0\n";
            else 
                cout << index[v][k - 1] << "\n";
        }
    }
    
    return 0;
}
