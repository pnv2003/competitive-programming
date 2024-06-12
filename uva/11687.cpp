#include <iostream>
#include <string>
using namespace std;

int numDigits(int n)
{
    if (n == 0)
        return 1;
    int count = 0;
    while (n > 0)
    {
        ++count;
        n /= 10;
    }

    return count;
}

int main(int argc, char const *argv[])
{
    string xs;
    for (;;)
    {
        cin >> xs;
        if (xs == "END") break;

        int x = xs.size();
        if (x == 1 && stoi(xs) == 1)
        {
            cout << "1\n";
        }
        else
        {
            int i = 1;
            int x_next;
            for (;;)
            {
                ++i;
                x_next = numDigits(x);
                if (x == x_next) break;
                x = x_next;
            }
            cout << i << "\n";
        }   
    }

    return 0;
}
