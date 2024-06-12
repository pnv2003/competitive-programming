#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
using li = long long;
using ld = long double;
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int main(int argc, char const *argv[])
{
    // FILEIO;
    li n, l, w;
    while (scanf(" %lld %lld %lld", &n, &l, &w) != EOF)
    {
        vector<pair<ld, ld>> intervals;
        while (n--)
        {
            li pos, rad;
            scanf(" %lld %lld", &pos, &rad);
            if (rad*2 < w)
                continue;
            ld r = sqrt((rad*rad*4 - w*w)/4.0);
            intervals.push_back({pos - r, pos + r});
        }

        sort(intervals.begin(), intervals.end(), 
            [](const pair<ld, ld>& p1, const pair<ld, ld>& p2)
            {
                if (p1.first < p2.first)
                    return true;
                if (p1.first > p2.first)
                    return false;
                return p1.second > p2.second;
            });

        ld prev = 0, 
            curend = 0, 
            newbegin = 0,
            newend = 0;
        int count = 0;
        bool pass = true;
        for (li i = 0; i < intervals.size(); ++i)
        {
            newbegin = intervals[i].first;
            newend = intervals[i].second;
            if (newend <= curend)
                continue;
            
            if (newbegin > curend) 
            {
                pass = false;
                break;
            }

            ++count;
            if (i > 0 && prev >= newbegin)
            { // exclude previous lierval
                --count;
                curend = newend;
            }
            else 
            {
                prev = curend;
                curend = newend;
            }
            if (curend >= l)
                break;
        }
        if (curend < l)
            pass = false;
        printf("%d\n", pass ? count : -1);
    }
    
    return 0;
}
