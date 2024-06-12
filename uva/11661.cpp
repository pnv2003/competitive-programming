#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    int len;
    string locs;
    for (;;)
    {
        cin >> len;
        if (len == 0) break;
        cin >> locs;     

        int mindist = len;
        int prepos = -1;
        for (int pos = 0; pos < len; ++pos)
        {
            char loc = locs[pos];
            if (loc == 'Z')
            {
                mindist = 0;
                break;
            }

            if (loc != '.')
            {
                if (prepos != -1)
                {
                    if (locs[prepos] != locs[pos] &&
                        pos - prepos < mindist)
                        mindist = pos - prepos;
                }
                prepos = pos;
            }
        }

        cout << mindist << "\n";
    }
    return 0;
}
