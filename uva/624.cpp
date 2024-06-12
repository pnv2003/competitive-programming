#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int trackcnt, taped, mind;
vector<int> trackd(20), tape_tracks, min_tape_tracks;

void fill_tape(int track)
{
    if (track == trackcnt || taped < 0) 
    {
        if (taped < 0)
        {
            if (taped + tape_tracks.back() < mind)
            {
                mind = taped + tape_tracks.back();
                min_tape_tracks = tape_tracks;
                min_tape_tracks.pop_back();
            }
        }
        else 
        {
            if (taped < mind)
            {
                mind = taped;
                min_tape_tracks = tape_tracks;
            }
        }
        return;
    }

    for (int i = track; i < trackcnt; ++i)
    {
        int d = trackd[i];
        taped -= d;
        tape_tracks.push_back(d);
        fill_tape(i + 1);
        taped += d;
        tape_tracks.pop_back();
    }
}

int main(int argc, char const *argv[])
{
    FASTIO;
    int n;
    while (cin >> n)
    {
        taped = n;
        mind = n;
        cin >> trackcnt;

        for (size_t i = 0; i < trackcnt; i++)
            cin >> trackd[i];
        fill_tape(0);
        
        for (int t: min_tape_tracks)
            cout << t << " ";
        cout << "sum:" << n - mind << "\n";
    }
    
    return 0;
}
