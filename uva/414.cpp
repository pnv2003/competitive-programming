#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int nrow;
    while (cin >> nrow)
    {
        if (nrow == 0) break;
        
        vector<string> img;
        while (nrow--)
        {
            string str;
            getline(cin >> ws, str);
            img.push_back(str);
        }

        vector<int> blank;
        for (const string& row: img)
        {
            int bcount = count(row.begin(), row.end(), ' ');
            blank.push_back(bcount);
        }

        int bmin = *min_element(blank.begin(), blank.end());
        int voidcount = 0;
        for (int b: blank)
            voidcount += (b - bmin);

        cout << voidcount << "\n";
    }
    
    return 0;
}
