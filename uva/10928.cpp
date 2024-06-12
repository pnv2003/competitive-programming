#include <iostream>
#include <string>
#include <sstream>
#include <queue>
using namespace std;
using ii = pair<int, int>;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int main(int argc, char const *argv[])
{
    FASTIO;
    int n;
    cin >> n;
    while (n--)
    {
        int p;
        cin >> p;

        string line;
        auto comp = [](const ii& p1, const ii& p2)
        {
            if (p1.second > p2.second) return true;
            if (p1.second < p2.second) return false;
            return p1.first > p2.first;
        };
        priority_queue<ii, vector<ii>, decltype(comp)> pq(comp);
        
        for (int i = 0; i < p; ++i)
        {
            getline(cin >> ws, line);
            stringstream ss{ line };

            int cnt = 0, nb;
            while (ss >> nb)
                ++cnt;
            
            pq.push({i + 1, cnt});
        }

        int minnb = pq.top().second;
        cout << pq.top().first;
        pq.pop();
        while (!pq.empty() && pq.top().second == minnb)
        {
            cout << " " << pq.top().first;
            pq.pop();
        }
        cout << "\n";
    }
    
    return 0;
}
