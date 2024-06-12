#include <iostream>
#include <vector>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int main(int argc, char const *argv[])
{
    FASTIO;

    int n;
    while (cin >> n)
    {
        if (n == 0) break;

        vector<int> vh;
        int h;
        while (n--)
        {   
            cin >> h;
            vh.push_back(h);
        }

        int peaks = 0;
        int trend;
        for (int i = 0; i <= vh.size(); ++i)
        {
            if (i == 0)
                trend = vh[0] - vh[vh.size() - 1];
            else 
            {
                int newtrend;
                if (i == vh.size()) 
                    newtrend =vh[0] - vh[vh.size() - 1];
                else 
                    newtrend = vh[i] - vh[i - 1];

                if (newtrend * trend < 0)
                    ++peaks;
                trend = newtrend;    
            }
        }

        cout << peaks << "\n";
    }
    
    return 0;
}
