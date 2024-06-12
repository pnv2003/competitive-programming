#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct
{
    string name;
    double price;
    int nreqmet;
} prop_t;
using vp = vector<prop_t>;
using vs = vector<string>;

int main(int argc, char const *argv[])
{
    int nreqs, nprops, id = 1;
    for (;;)
    {
        cin >> nreqs >> nprops;
        if (nreqs == 0 && nprops == 0) break;
        
        if (id > 1) cout << "\n";
        vs vreq;
        string req;
        while (nreqs--)
        {
            getline(cin >> ws, req);
            vreq.push_back(req);
        }

        vp vprop;
        string name;
        double price;
        int nreqmet;
        while (nprops--)
        {
            getline(cin, name);
            cin >> price >> nreqmet;
            cin.ignore();
            vprop.push_back(prop_t{ name, price, nreqmet });

            string reqmet;
            while (nreqmet--)
                getline(cin >> ws, reqmet);
        }

        auto bestprop = *max_element(vprop.begin(), vprop.end(),
                                     [](const prop_t& t1, const prop_t& t2)
                                     {
                                        if (t1.nreqmet < t2.nreqmet)
                                            return true;
                                        if (t1.nreqmet > t2.nreqmet)
                                            return false;
                                        // ==
                                        return (t1.price > t2.price);
                                     });

        cout << "RFP #" << id++ << "\n";
        cout << bestprop.name << "\n";
    }
    return 0;
}

