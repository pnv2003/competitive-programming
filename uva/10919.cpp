#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
using vs = vector<string>;

int main(int argc, char const *argv[])
{
    int ncourse, ncat;
    while (cin >> ncourse >> ncat)
    {
        vs vcid;
        string cid;
        while (ncourse--)
        {
            cin >> cid;
            vcid.push_back(cid);
        }

        int ncourse_all, ncourse_min, ncourse_taken;
        bool preq_satisfied = true;
        string cid_cat;
        while (ncat--)
        {
            cin >> ncourse_all >> ncourse_min;
            ncourse_taken = 0;
            while (ncourse_all--)
            {
                cin >> cid_cat;
                auto f = find(vcid.begin(), vcid.end(), cid_cat);
                if (f != vcid.end())
                    ++ncourse_taken;
            }
            if (ncourse_taken < ncourse_min)
                preq_satisfied = false;
        }

        cout <<
        (
            preq_satisfied ?
            "yes\n" :
            "no\n"
        );
    }
    return 0;
}
