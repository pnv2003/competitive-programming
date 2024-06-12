#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, id = 1;
    while (cin >> n)
    {
        if (n == 0) break;

        vector<int> stacks;
        int count = 0;
        while (n--)
        {
            int i;
            cin >> i;
            count += i;
            stacks.push_back(i);
        }

        int height = count / stacks.size();
        int nmoves = 0;
        for (int s: stacks)
        {
            if (s > height)
                nmoves += (s - height);
        }
;
        cout << "Set #" << id++ 
             << "\nThe minimum number of moves is "
             << nmoves
             << ".\n\n";
    }
    
    return 0;
}
