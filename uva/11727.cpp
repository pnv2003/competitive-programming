#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int t, id = 1;
    vector<int> v(3);
    cin >> t;
    while (t--)
    {
        cin >> v[0] >> v[1] >> v[2];
        sort(v.begin(), v.end());
        
        cout << "Case " << id << ": " << v[1] << "\n"; 
        ++id;
    }
    return 0;
}
