#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <unordered_set>
#include <map>
#include <stdexcept>
using namespace std;
using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vvi = vector<vector<int>>;
using vs = vector<string>;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

// Disjoint Sets Forest implementation
template <typename T>
class DisjointSets
{
public:
    using rank_t = int;
    using setsize_t = int;
    struct Node 
    {
        T value;
        rank_t rank;
        Node* parent;
    };

private:
    std::map<T, Node*> nodemap{};
    std::map<T, setsize_t> setsize{}; // map the representative nodes and its set size

    void _make_set(Node* x);
    Node* _find_set(Node* x) const;
    void _link(Node* x, Node* y);
    void _union(Node* x, Node* y);

public:
    DisjointSets() = default;
    DisjointSets(const DisjointSets& other);
    ~DisjointSets();

    setsize_t number_of_sets() const;
    setsize_t size_of_set(const T& x) const;

    void make_set(const T& x);
    bool contains(const T& x) const;
    T find_set(const T& x) const;
    bool same_set(const T& x, const T& y) const;
    void join(const T& x, const T& y);
};

// -----------------------------------------------------

template <typename T>
DisjointSets<T>::DisjointSets(const DisjointSets& other)
{
    throw std::runtime_error("disjoint sets' copy constructor have not been implemented yet");
}

template <typename T>
DisjointSets<T>::~DisjointSets()
{
    for (const auto& p: nodemap)
        delete p.second;
}

template <typename T>
typename DisjointSets<T>::setsize_t DisjointSets<T>::number_of_sets() const
{
    return setsize.size();
}

template <typename T>
typename DisjointSets<T>::setsize_t DisjointSets<T>::size_of_set(const T& x) const
{
    return setsize.at(find_set(x));
}

template <typename T>
void DisjointSets<T>::make_set(const T& x)
{
    Node* node = new Node{ x, 0, nullptr };
    nodemap[x] = node;
    setsize[x] = 1;
    _make_set(node);
}

template <typename T>
bool DisjointSets<T>::contains(const T& x) const
{
    return nodemap.count(x) == 0 ? false : true;
}

template <typename T>
T DisjointSets<T>::find_set(const T& x) const
{
    if (nodemap.count(x) == 0)
        throw std::runtime_error("element not found in the disjoint sets");

    return _find_set(nodemap.at(x))->value;
}

template <typename T>
bool DisjointSets<T>::same_set(const T& x, const T& y) const
{
    return find_set(x) == find_set(y);
}

template <typename T>
void DisjointSets<T>::join(const T& x, const T& y) 
{
    _union(nodemap[x], nodemap[y]);
}

// -----------------------------------------------------

template <typename T>
void DisjointSets<T>::_make_set(Node* x)
{
    x->parent = x;
    x->rank = 0;
}

template <typename T>
typename DisjointSets<T>::Node* DisjointSets<T>::_find_set(Node* x) const
{
    if (x != x->parent)
        x->parent = _find_set(x->parent);
    return x->parent;
}

template <typename T>
void DisjointSets<T>::_link(Node* x, Node* y)
{
    if (x->rank > y->rank)
    {
        y->parent = x;
        setsize[x->value] += setsize.at(y->value);
        setsize.erase(y->value);
    }
    else
    {
        x->parent = y;
        setsize[y->value] += setsize.at(x->value);
        setsize.erase(x->value);
        if (x->rank == y->rank)
            y->rank++;
    }
}

template <typename T>
void DisjointSets<T>::_union(Node* x, Node* y)
{
    Node* xrepr = _find_set(x);
    Node* yrepr = _find_set(y);
    if (xrepr != yrepr)
        _link(xrepr, yrepr);
}

int main(int argc, char const *argv[])
{
    FASTIO;
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        vii edges;

        while (cin >> str && str[0] != '*')
        {
            ii e = { str[1] - 'A', str[3] - 'A' };
            edges.push_back(e);
        }

        DisjointSets<int> ds;
        cin >> str;
        for (char c: str)
        {
            if (c == ',') continue;
            ds.make_set(c - 'A');
        }

        for (const auto& e: edges)
            ds.join(e.first, e.second);

        unordered_set<int> trees, acorns;
        for (char c: str)
        {
            if (c == ',') continue;
            int s = ds.find_set(c - 'A');
            if (ds.size_of_set(s) == 1)
                acorns.insert(s);
            else
                trees.insert(s);
        }

        cout << "There are "
             << trees.size()
             << " tree(s) and "
             << acorns.size()
             << " acorn(s).\n";
    }
    return 0;
}