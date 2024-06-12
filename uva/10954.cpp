#include <iostream>
#include <queue>
using namespace std;
using ll = long long;

int main(int argc, char const *argv[])
{
    int n;
    while (cin >> n && n != 0)
    {
        priority_queue<ll, vector<ll>, greater<ll>> numset;
        while (n--)
        {
            ll num; 
            cin >> num;
            numset.push(num);
        }

        ll cost = 0;
        while (numset.size() > 1)
        {
            auto fst = numset.top();
            numset.pop();
            auto snd = numset.top();
            numset.pop();
            auto sum = fst + snd;
            cost += sum;
            numset.push(sum);
        }
        cout << cost << "\n";           
    }
    
    return 0;
}
