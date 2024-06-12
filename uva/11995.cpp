#include <iostream>
#include <stack>
#include <queue>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int main(int argc, char const *argv[])
{
    FASTIO;
    int n;
    while (cin >> n)
    {
        bool checks = true, checkq = true, checkpq = true;
        int cmd, val;
        stack<int> s; 
        queue<int> q; 
        priority_queue<int> pq;
        while (n--)
        {
            cin >> cmd >> val;
            if (cmd == 1)
            {
                if (checks)
                    s.push(val);
                if (checkq)
                    q.push(val);
                if (checkpq)
                    pq.push(val);
            }
            else 
            {
                if (checks)
                {
                    if (s.empty()) 
                        checks = false;
                    else if (s.top() != val) 
                        checks = false;
                    else s.pop();
                }
                if (checkq)
                {
                    if (q.empty())
                        checkq = false;
                    else if (q.front() != val)
                        checkq = false;
                    else q.pop();
                }
                
                if (checkpq)
                {
                    if (pq.empty())
                        checkpq = false;
                    else if (pq.top() != val)
                        checkpq = false;
                    else pq.pop();
                }
                
            }
        }

        int cnt = 0;
        if (checks) ++cnt;
        if (checkq) ++cnt;
        if (checkpq) ++cnt;

        if (cnt == 0)
            cout << "impossible\n";
        else if (cnt == 1)
        {
            if (checks)
                cout << "stack\n";
            else if (checkq)
                cout << "queue\n";
            else
                cout << "priority queue\n";
        }
        else 
            cout << "not sure\n";
    }
    
    return 0;
}
