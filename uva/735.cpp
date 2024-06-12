#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    set<int> regions;
    regions.insert(0); // missed
    for (int i = 1; i <= 20; ++i)
    {
        regions.insert(i);
        regions.insert(i*2);
        regions.insert(i*3);
    }
    regions.insert(50); // bullseye

    int score;
    while (cin >> score && score > 0)
    {
        int ncomb = 0, nperm = 0;
        bool ok = false;
        for (auto it = regions.begin(); it != regions.end(); ++it)
        {
            for (auto jt = it; jt != regions.end(); ++jt)
            {
                for (auto kt = jt; kt != regions.end(); ++kt)
                {
                    if (*it + *jt + *kt == score)
                    {
                        ok = true;
                        ++ncomb;

                        vector<int> comb{*it, *jt, *kt};
                        do
                        {
                            ++nperm;
                        } while (next_permutation(comb.begin(), comb.end()));
                    }
                }
            }
        }

        if (ok)
        {
            cout << "NUMBER OF COMBINATIONS THAT SCORES " << score << " IS " << ncomb << ".\n";
            cout << "NUMBER OF PERMUTATIONS THAT SCORES " << score << " IS " << nperm << ".\n";
        }
        else 
            cout << "THE SCORE OF " << score << " CANNOT BE MADE WITH THREE DARTS.\n";
        cout << string(70, '*') << "\n";
    }
    cout << "END OF OUTPUT\n";

    return 0;
}
