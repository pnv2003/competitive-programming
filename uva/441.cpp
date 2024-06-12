#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int main(int argc, char const *argv[])
{
    FASTIO;

    int k, id = 1;
    while (cin >> k)
    {
        if (k == 0) break;

        vector<int> s;
        for (int i = 0; i < k; ++i)
        {
            int num;
            cin >> num;
            s.push_back(num);
        }

        sort(s.begin(), s.end());

        if (id++ > 1)
            cout << "\n";
        for (int a = 0; a < k; ++a)
            for (int b = a + 1; b < k; ++b)
                for (int c = b + 1; c < k; ++c)
                    for (int d = c + 1; d < k; ++d)
                        for (int e = d + 1; e < k; ++e)
                            for (int f = e + 1; f < k; ++f)
                                cout << s[a] << " "
                                     << s[b] << " "
                                     << s[c] << " "
                                     << s[d] << " "
                                     << s[e] << " "
                                     << s[f] << "\n";
    }
    
    return 0;
}
