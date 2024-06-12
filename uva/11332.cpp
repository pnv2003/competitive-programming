#include <iostream>
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
    int n;
    for (;;)
    {
        cin >> n;
        if (n == 0) break;
        while (n > 9)
            n = sumDigits(n);
        cout << n << "\n";
    }
    return 0;
}
