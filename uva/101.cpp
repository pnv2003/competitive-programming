#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
using vi = vector<int>;
using vii = vector<vi>;
using ii = pair<int, int>;

void bw_init(vii& piles, vector<ii>& position, int sz)
{
    for (int i = 0; i < sz; ++i)
    {
        vector<int> pile;
        pile.push_back(i);
        piles[i] = pile;
        position[i] = {i, 0};
    }
}

void bw_move_block(vii& piles, vector<ii>& position, int srcpileid, int dstpileid)
{
    vi& srcpile = piles[srcpileid];
    vi& dstpile = piles[dstpileid];

    int block = srcpile.back();
    srcpile.pop_back();
    dstpile.push_back(block);
    position[block] = {dstpileid, dstpile.size() - 1};
}

void bw_move_pile(vii& piles, vector<ii>& position, const ii& pos, int dstpileid)
{
    vi& srcpile = piles[pos.first];
    vi& dstpile = piles[dstpileid];

    auto it = srcpile.begin() + pos.second;
    while (it != srcpile.end())    
    {
        dstpile.push_back(*it);
        position[*it] = {dstpileid, dstpile.size() - 1};
        it = srcpile.erase(it);
    }
}

void bw_free(vii& piles, vector<ii>& position, const ii& pos)
{
    vi& srcpile = piles[pos.first];
    while (pos.second + 1 != srcpile.size())
        bw_move_block(piles, position, pos.first, srcpile.back());
}

int main(int argc, char const *argv[])
{
    FASTIO;

    int n;
    cin >> n;
    
    vii piles(n);
    vector<ii> position(n);
    bw_init(piles, position, n);
    string cmd1, cmd2;
    int src, dst;
    while (cin >> cmd1)
    {
        if (cmd1 == "quit") break;

        cin >> src >> cmd2 >> dst;

        if (src == dst)
            continue;

        auto srcpos = position[src];
        auto dstpos = position[dst];
        if (srcpos.first == dstpos.first)
            continue;
        
        if (cmd1 == "move")
        {
            if (cmd2 == "onto")
            { // move onto
                bw_free(piles, position, srcpos);
                bw_free(piles, position, dstpos);
                bw_move_block(piles, position, srcpos.first, dstpos.first);
            }
            else
            { // move over
                bw_free(piles, position, srcpos);
                bw_move_block(piles, position, srcpos.first, dstpos.first);
            }
        }
        else
        {
            if (cmd2 == "onto")
            { // pile onto
                bw_free(piles, position, dstpos);
                bw_move_pile(piles, position, srcpos, dstpos.first);
            }
            else
            { // pile over
                bw_move_pile(piles, position, srcpos, dstpos.first);
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        cout << i << ":";
        for (int j = 0; j < piles[i].size(); ++j)
            cout << " " << piles[i][j];
        cout << "\n";
    }

    return 0;
}
