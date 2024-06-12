#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct
{
    int num;
    bool matched;
} codenum_t;
using code_t = vector<codenum_t>;

int main(int argc, char const *argv[])
{
    int codelen, id = 1;
    while (cin >> codelen)
    {
        if (codelen == 0) break;

        code_t scode(codelen, codenum_t{ 0, false });
        for (int i = 0; i < codelen; ++i)
            cin >> scode[i].num;
        
        cout << "Game " << id++ << ":\n";
        for (;;)
        {
            for_each(scode.begin(), scode.end(), 
                    [](codenum_t& c){ c.matched = false; });

            code_t guess(codelen, codenum_t{ 0, false });
            int nzero = 0;
            for (int i = 0; i < codelen; ++i) 
            {
                cin >> guess[i].num;
                if (guess[i].num == 0) ++nzero;
            }
            if (nzero == codelen) 
                break;
            
            int nstrong = 0, nweak = 0;
            for (int i = 0; i  < codelen; ++i)
            {
                if (scode[i].num == guess[i].num) 
                {
                    ++nstrong;
                    scode[i].matched = true;
                    guess[i].matched = true;
                }
            }

            for (auto it = scode.begin(); it != scode.end(); ++it)
            {
                if (!it->matched)
                {
                    auto found = find_if(guess.begin(), guess.end(), 
                                        [&it](codenum_t c)
                                        { return (c.num == it->num && !c.matched); });
                    if (found != guess.end())
                    {
                        ++nweak;
                        found->matched = true;
                    }
                }
                it->matched = true;
            }
            cout << "    (" << nstrong << "," << nweak << ")\n";
        }
    }
    return 0;
}
