#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> seq;
    int num, cnt = 0;
    while (cin >> num)
    {
        seq.push_back(num);
        ++cnt;
        sort(seq.begin(), seq.end());
        if (cnt % 2 == 0)
            cout << (seq[cnt / 2] + seq[cnt / 2 - 1]) / 2;
        else
            cout << seq[cnt / 2];
        cout << "\n";
    }
    
    return 0;
}
