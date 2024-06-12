#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int main(int argc, char const *argv[])
{
    FASTIO;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> score;
        while (n--)
        {
            int s;
            cin >> s;
            score.push_back(s);
        }

        int maxscore = score[0];
        int maxdiff = INT_MIN;
        for (int i = 1; i < score.size(); ++i)
        {
            if (score[i] > maxscore)
            {
                maxdiff = max(maxdiff, maxscore - score[i]);
                maxscore = score[i];
                continue;
            }
            
            maxdiff = max(maxdiff, maxscore - score[i]);
        }
        cout << maxdiff << "\n";
    }
    
    return 0;
}
