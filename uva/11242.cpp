#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int f, r;
    while (cin >> f >> r)
    {
        vector<int> front(f), rear(r);
        for (int i = 0; i < f; ++i)
            cin >> front[i];
        for (int i = 0; i <r; ++i)
            cin >> rear[i];

        vector<double> ratio;
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < f; ++j)
                ratio.push_back(rear[i]*1.0 / front[j]);

        sort(ratio.begin(), ratio.end());

        double maxspread = 0.0;
        for (int i = 0; i < ratio.size() - 1; ++i)
        {
            maxspread = max(maxspread, ratio[i + 1] / ratio[i]);
        }
        
        printf("%.2f\n", maxspread);
    }
    
    return 0;
}
