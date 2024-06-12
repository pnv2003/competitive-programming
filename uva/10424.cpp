#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int sumDigits(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    string n1, n2;
    while (getline(cin >> ws, n1) && getline(cin >> ws, n2))
    {
        int v1 = 0, v2 = 0;
        for (char c: n1)
        {
            if (c >= 'a' && c <= 'z')
                v1 += (c - 'a') + 1;
            else if (c >= 'A' && c <= 'Z')
                v1 += (c - 'A') + 1;
            while (v1 > 9)
                v1 = sumDigits(v1);
        }
        for (char c: n2)
        {
            if (c >= 'a' && c <= 'z')
                v2 += (c - 'a') + 1;
            else if (c >= 'A' && c <= 'Z')
                v2 += (c - 'A') + 1;
            while (v2 > 9)
                v2 = sumDigits(v2);
        }

        double ratio = v1*1.0 / v2;
        if (ratio > 1.0)
            ratio = 1.0 / ratio;

        cout << fixed << setprecision(2) << ratio * 100 << " %\n";
    }
    return 0;
}
