#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;
using field_t = vector<string>;

void mine_is_near(field_t& f, int r, int c)
{
    if (r >= 0 && r < f.size() && 
        c >=0 && c < f[0].size())
    {
        if (f[r][c] == 'x' || f[r][c] == '0')
            f[r][c] = '1';
        else if (isdigit(f[r][c]))
            ++f[r][c];
    }
}

void mine_is_far(field_t& f, int r, int c)
{
    if (f[r][c] == 'x')
        f[r][c] = '0';
}

field_t touch_field(const field_t& mf, const field_t& pf)
{
    field_t rf = pf;
    int nrow = mf.size(), ncol = mf[0].size();
    bool mineblown = false;
    for (int i = 0; i < nrow; ++i)
    {
        for (int j = 0; j < ncol; ++j)
        {
            if (mf[i][j] == '*')
            {
                if (pf[i][j] == 'x') // oops
                    mineblown = true;
                
                mine_is_near(rf, i - 1, j);
                mine_is_near(rf, i - 1, j + 1);
                mine_is_near(rf, i, j + 1);
                mine_is_near(rf, i + 1, j + 1);
                mine_is_near(rf, i + 1, j);
                mine_is_near(rf, i + 1, j - 1);
                mine_is_near(rf, i, j - 1);
                mine_is_near(rf, i - 1, j - 1);
            }
            else if (mf[i][j] == '.')
                mine_is_far(rf, i, j);
        }
    }

    if (mineblown)
    {
        for (int i = 0; i < nrow; ++i)
        {
            for (int j = 0; j < ncol; ++j)
            {
                if (mf[i][j] == '*')
                    rf[i][j] = '*';
            }
        }
    }

    return rf;
}

int main(int argc, char const *argv[])
{
    int t, fsize, id = 1;
    cin >> t;
    while (cin >> fsize)
    {
        field_t minefield(fsize);
        for (int i = 0; i < fsize; ++i)
            cin >> minefield[i];

        field_t playerfield(fsize);
        for (int i = 0; i < fsize; ++i)
            cin >> playerfield[i];

        field_t result = touch_field(minefield, playerfield);
    
        if (id++ > 1)
            cout << "\n";
        for (int i = 0; i < fsize; ++i)
            cout << result[i] << "\n";
    }
    
    return 0;
}
