#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

struct Query
{
    int qid;
    int period;
    int next;
};

int main(int argc, char const *argv[])
{
    FASTIO;
    auto stream_prio = 
    [](Query q1, Query q2)
    {
        if (q1.next > q2.next)
            return true;
        if (q1.next < q2.next)
            return false;
        return (q1.qid > q2.qid);
    };

    string cmd; 
    int qid, period;
    priority_queue<Query, vector<Query>, decltype(stream_prio)> stream(stream_prio);
    while (cin >> cmd && cmd != "#")
    {
        cin >> qid >> period;
        stream.push({qid, period, period});
    }

    int k;
    cin >> k;
    while (k--)
    {
        auto res = stream.top();
        stream.pop();
        cout << res.qid << "\n";
        res.next += res.period;
        stream.push(res);
    }
    
    
    return 0;
}
