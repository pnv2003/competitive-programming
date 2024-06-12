#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct AmmArray
{
    int base_addr;
    int elem_size;
    int ndim;
    vector<pair<int,int>> bound;
};

int main(int argc, char const *argv[])
{
    int narr, nref;
    cin >> narr >> nref;

    map<string, AmmArray> map_arr;
    while (narr--)
    {
        string name;
        AmmArray arr;
        cin >> name 
            >> arr.base_addr 
            >> arr.elem_size
            >> arr.ndim;
        for (int i = 0; i < arr.ndim; ++i)
        {
            int lb, ub;
            cin >> lb >> ub;
            arr.bound.push_back({lb, ub});
        }
        map_arr[name] = arr;
    }

    while (nref--)
    {
        string name;
        cin >> name;
        AmmArray arr = map_arr[name];
        vector<int> idx(arr.ndim, 0);
        for (int i = 0; i < arr.ndim; ++i)
            cin >> idx[i];
        
        int phy_addr = 0;
        vector<int> constants(arr.ndim + 1, 0);
        for (int i = arr.ndim; i > 0; --i)
        {
            if (i == arr.ndim)
                constants[i] = arr.elem_size;
            else
                constants[i] = constants[i + 1] * (arr.bound[i].second - arr.bound[i].first + 1);
        }
        constants[0] = arr.base_addr;
        for (int i = 1; i < arr.ndim + 1; ++i)
        {
            constants[0] -= constants[i] * arr.bound[i - 1].first;
        }
        phy_addr = constants[0];
        for (int i = 1; i < arr.ndim + 1; ++i)
        {
            phy_addr += constants[i] * idx[i - 1];
        }

        cout << name << "[";
        for (int i = 0; i < arr.ndim; ++i)
        {
            cout << idx[i];
            if (i + 1 == arr.ndim)
                cout << "]";
            else
                cout << ", ";
        }
        cout << " = " << phy_addr << "\n";
    }
    
    
    return 0;
}
