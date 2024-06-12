#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int main(int argc, char const *argv[])
{
    // FILEIO;
    int n, m;
    while (scanf(" %d %d", &n, &m) != EOF)
    {
        if (n == 0 && m == 0) break;

        vector<int> diameter, height;
        while (n--)
        {
            int d;
            scanf(" %d", &d);
            diameter.push_back(d);
        }
        while (m--)
        {
            int h;
            scanf(" %d", &h);
            height.push_back(h);
        }

        sort(diameter.begin(), diameter.end());
        sort(height.begin(), height.end());

        int coin = 0;
        int d = 0, h = 0;
        bool pass = true;
        while (d < diameter.size())
        {
            if (h >= height.size())
            {
                pass = false;
                break;
            }
            if (diameter[d] <= height[h])
            {
                coin += height[h];
                ++d;
            }
            ++h;
        }
        
        pass 
            ? printf("%d\n", coin)
            : printf("Loowater is doomed!\n");
    }
    
    return 0;
}
