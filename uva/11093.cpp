#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ALL(x) x.begin(), x.end()
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

int main(int argc, char const *argv[])
{
    FASTIO;

    int t, id = 1;
    cin >> t;
    while (t--)
    {
        int nstation;
        cin >> nstation;

        vector<int> pet;
        int p;
        for (int i = 0; i < nstation; ++i)
        {
            cin >> p;
            pet.push_back(p);
        }
        for (int i = 0; i < nstation; ++i)
        {
            cin >> p;
            pet[i] -= p;
        }

        cout << "Case " << id++ << ": ";

        int psum = 0;
        for (int p: pet)
            psum += p;

        if (psum < 0)
        {
            cout << "Not possible\n";
            continue;
        }

        int init;
        bool completed = false;
        for (init = 0; init < nstation; ++init)
        {
            psum = 0;
            bool stop = false;
            int pos = init;
            do
            {
                psum += pet[pos];
                if (psum < 0)
                {
                    stop = true;
                    break;
                }
                pos = (pos + 1) % nstation;
            } while (pos != init);

            if (!stop)
            {
                completed = true;
                break;
            }
        }

        if (completed)
            cout << "Possible from station " << init + 1 << "\n";
        else
            cout << "Not possible\n";
    }
    return 0;
}
