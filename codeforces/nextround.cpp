#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    int kth;
    if (k - 1 >= v.size())
        kth = 0;
    else
        kth = v[k - 1];
    int next = 0;
    for (int i: v)
    {
        if (i >= kth && i > 0)
            ++next;
    }
    cout << next;
    
    return 0;
}