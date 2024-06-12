#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    string w;
    cin >> n;
    while (cin >> w)
    {
        if (w.size() == 5)
            cout << "3\n";
        else
        {
            int count = 0;
            if (w[0] == 'o')
                ++count;
            if (w[1] == 'n')
                ++count;
            if (w[2] == 'e')
                ++count;
            if (count >= 2)
                cout << "1\n";
            else 
                cout << "2\n";
        }
    }
    return 0;
}
