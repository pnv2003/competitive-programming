#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    double h, up, down, fat;
    for (;;)
    {
        cin >> h >> up >> down >> fat;
        if (h == 0) break;

        double updecr = up * fat / 100;
        int day = 1;
        double hclimbed = 0.0;
        for (;;)
        {
            if (up > 0)
                hclimbed += up;
            if (hclimbed > h)
            {
                cout << "success on day " << day << "\n";
                break;
            }
            hclimbed -= down;
            if (hclimbed < 0)
            {
                cout << "failure on day " << day << "\n";
                break;
            }
            up -= updecr;
            ++day;
        }
    }
    return 0;
}
