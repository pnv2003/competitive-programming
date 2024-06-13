#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

int main(int argc, char const *argv[])
{
    FASTIO;
    // FILEIO;
    string line;
    int row = 9;
    vector<string> vw{};
    vector<string> vb{};

    while (getline(cin >> ws, line))
    {
        if (line[0] == '+') {
            row--;
            continue;
        }

        stringstream ss(line);
        char col = 'a';
        string sq;
        while (getline(ss, sq, '|'))
        { 
            if (sq.size() != 3) {
                continue;
            } 
            if (sq[1] == '.' || sq[1] == ':') {
                col += 1;
                continue;
            }
            string piece = "";
            if (tolower(sq[1]) != 'p') {
                piece += static_cast<char>(toupper(sq[1]));
            }
            piece += static_cast<char>(col);
            piece += to_string(row);

            if (isupper(sq[1])) { // white
                vw.push_back(piece);
            } else { // black
                vb.push_back(piece);
            }

            col += 1;
        }
    }

    auto rank = [](const string& p){
        switch (p[0])
        {
        case 'K': return 5;
        case 'Q': return 4;
        case 'R': return 3;
        case 'B': return 2;
        case 'N': return 1;    
        default: break;
        }
        return 0;
    };

    sort(vw.begin(), vw.end(), 
        [rank](const string& p1, const string& p2){
            if (rank(p1) > rank(p2)) {
                return true;
            }
            if (rank(p1) < rank(p2)) {
                return false;
            }

            if (p1.back() < p2.back()) {
                return true;
            }
            if (p1.back() > p2.back()) {
                return false;
            }
            return p1[p1.size() - 2] < p2[p2.size() - 2];            
        });

    sort(vb.begin(), vb.end(),
        [rank](const string& p1, const string& p2){
            if (rank(p1) > rank(p2)) {
                return true;
            }
            if (rank(p1) < rank(p2)) {
                return false;
            }

            if (p1.back() > p2.back()) {
                return true;
            }
            if (p1.back() < p2.back()) {
                return false;
            }
            return p1[p1.size() - 2] < p2[p2.size() - 2];
        });
    
    cout << "White:";
    for (int i = 0; i < vw.size(); ++i) {
        if (i == 0) {
            cout << " ";
        } else {
            cout << ",";
        }
        cout << vw[i];
    }
    cout << "\nBlack:";
    for (int i = 0; i < vb.size(); ++i) {
        if (i == 0) {
            cout << " ";
        } else {
            cout << ",";
        }
        cout << vb[i];
    }

    return 0;
}
