#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using vi = vector<int>;

int main(int argc, char const *argv[])
{
    int height, length;
    for (;;)
    {
        cin >> height >> length;
        if (height == 0) break;

        vi v_piece_pos(height, -1);
        int piece_count = 0;
        int hi;
        for (int i = 0; i < length; ++i)
        {
            cin >> hi;
            for (int j = 0; j < hi; ++j)
                v_piece_pos[j] = -1;
            for (int j = hi; j < height; ++j)
            {
                if (v_piece_pos[j] == -1) {
                    ++piece_count;
                    v_piece_pos[j] = i;
                }
            }
        }

        cout << piece_count << "\n";
    }
    return 0;
}
