#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int t, id = 1;
    cin >> t;

    int walls;
    while (t--)
    {   
        cin >> walls;
        int h = 0, l = 0, j1 = 0, j2;
        while (walls--)
        {
            cin >> j2;
            if (j1 != 0)
            {
                if (j2 > j1) ++h;
                else if (j2 < j1) ++l;
            }
            j1 = j2;
        }
        cout << "Case " << id++ << ": " << h << " " << l << "\n";
    }
    return 0;
}
