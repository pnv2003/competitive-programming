#include <iostream>
using namespace std;
int main()
{
    int w;
    cin >> w;
    if (w == 2) 
        cout << "NO";
    else
        cout << ((w % 2 == 0) ? "YES" : "NO");
    return 0;
};