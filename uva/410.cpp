#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int main(int argc, char const *argv[])
{
    // FILEIO;
    int c, s, id = 1;
    while (scanf(" %d %d", &c, &s) != EOF)
    {
        vector<int> mass(2*c, 0);
        int pos[1000]{};
        pos[0] = 100;
        for (int i = 0; i < s; ++i) {
            scanf(" %d", &mass[i]);
            pos[mass[i]] = i;
        }

        sort(mass.begin(), mass.end());

        double avg = 0;
        for (int m: mass)
            avg += m*1.0;
        avg /= c*1.0;

        double imbal = 0;
        int i = 0;
        vector<pair<int, int>> cham;
        while (i < mass.size())
        {
            imbal += abs(mass[i] + mass.back() - avg);
            if (mass[i] == 0 || pos[mass.back()] < pos[mass[i]])
                cham.push_back({mass.back(), mass[i]});
            else 
                cham.push_back({mass[i], mass.back()});
            mass.pop_back();
            ++i;
        }

        sort(cham.begin(), cham.end(),
            [&pos](const pair<int, int>& p1, const pair<int, int>& p2)
            {
                if (pos[p1.first] < pos[p2.first])
                    return true;
                if (pos[p1.first] > pos[p2.first])
                    return false;
                return pos[p1.second] < pos[p2.second];
            });

        printf("Set #%d\n", id++);
        for (int i = 0; i < cham.size(); ++i)
        {
            printf("%2d:", i);
            if (cham[i].first != 0)
                printf(" %d", cham[i].first);
            if (cham[i].second != 0)
                printf(" %d", cham[i].second);
            printf("\n");
        }
        printf("IMBALANCE = %.5f\n\n", imbal);
    }
    
    return 0;
}
