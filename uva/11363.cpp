#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using vi = vector<int>;
#define ALL(x) x.begin(), x.end()

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int num, pos;
        vi v;
        cin >> num;
        while (num--)
        {
            cin >> pos;
            v.push_back(pos);
        }
        cout << (*max_element(ALL(v)) - *min_element(ALL(v))) * 2 << "\n";
    }
    return 0;
}
