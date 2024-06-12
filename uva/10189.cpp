#include <iostream>
#include <string>
#include <vector>
using namespace std;
using field_t = vector<string>;

void mine_is_near(field_t& f, int r, int c)
{
    if (r >= 0 && r < f.size() && 
        c >=0 && c < f[0].size() &&
        f[r][c] != '*')
    {
        if (f[r][c] == '.' || f[r][c] == '0')
            f[r][c] = '1';
        else
            ++f[r][c];
    }
}

int main(int argc, char const *argv[])
{
    int nrow, ncol, id = 1;
    while (true)
    {
        cin >> nrow >> ncol;
        if (nrow == 0) break;

        field_t field(nrow);
        for (int i = 0; i < nrow; i++)
            cin >> field[i];
        
        for (int i = 0; i < nrow; ++i)
        {
            for (int j = 0; j < ncol; ++j)
            {
                if (field[i][j] == '*')
                {
                    mine_is_near(field, i - 1, j);
                    mine_is_near(field, i - 1, j + 1);
                    mine_is_near(field, i, j + 1);
                    mine_is_near(field, i + 1, j + 1);
                    mine_is_near(field, i + 1, j);
                    mine_is_near(field, i + 1, j - 1);
                    mine_is_near(field, i, j - 1);
                    mine_is_near(field, i - 1, j - 1);
                }
                else if (field[i][j] == '.')
                    field[i][j] = '0';   
            }
        }

        if (id > 1)
            cout << "\n";
        cout << "Field #" << id++ << ":\n";
        for (int i = 0; i < nrow; ++i)
            cout << field[i] << "\n";
    }
    
    return 0;
}
