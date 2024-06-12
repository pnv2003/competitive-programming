#include <iostream>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int t, id = 1;
    cin >> t;
    while (t--)
    {
        string sen;
        getline(cin >> ws, sen);

        auto last = remove_if(sen.begin(), sen.end(), [](char c){ return !isalpha(c); });
        sen.erase(last, sen.end());

        auto k = static_cast<int>(sqrt(sen.size()*1.0));

        cout << "Case #" << id++ << ":\n";
        if (k * k == sen.size())
        {
            vector<string> table;
            string row;
            for (int i = 0; i < sen.size(); ++i)
            {  
                row.push_back(sen[i]);
                
                if ((i + 1) % k == 0)
                {
                    table.push_back(row);
                    row.clear();
                }
            }

            string sen_trans;
            vector<string> table_trans(k, string(k, ' '));
            for (int i = 0; i < k; ++i)
            {
                for (int j = 0; j < k; ++j)
                    table_trans[i][j] = table[j][i];
            }
            for (const string& row: table_trans)
                sen_trans.append(row);

            string sen_rev = sen, 
                   sen_trans_rev = sen_trans;

            reverse(sen_rev.begin(), sen_rev.end());
            reverse(sen_trans_rev.begin(), sen_trans_rev.end());

            
            if (sen == sen_trans &&
                sen == sen_rev &&
                sen == sen_trans_rev) 
            {
                cout << k << "\n"; 
                continue;
            }          
        }

        cout << "No magic :(\n";
    }
    
    return 0;
}