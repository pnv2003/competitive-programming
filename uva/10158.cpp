#include <iostream>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

#include <unordered_map>
#include <stdexcept>

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
    std::unordered_map<T, Node*> nodemap{};
    std::unordered_map<T, setsize_t> setsize{}; // map the representative nodes and its set size

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
    int n;
    cin >> n;

    DisjointSets<int> ds;
    for (int i = 0; i < n; ++i)
        ds.make_set(i);
    
    unordered_map<int, int> enemies; 

    int c, x, y;
    while (cin >> c >> x >> y && !(c == 0 && x == 0 && y == 0))
    {
        switch (c)
        {
        case 1: // set friends
            if (enemies.count(x) && ds.same_set(enemies[x], y))
                cout << "-1\n";
            else if (enemies.count(y) && ds.same_set(enemies[y], x))
                cout << "-1\n";
            else
            {
                ds.join(x, y);
                if (enemies.count(x) && enemies.count(y))
                    ds.join(enemies[x], enemies[y]);
            }
            break;
        case 2: // set enemies
            if (x == y)
                cout << "-1\n";
            else if (ds.contains(x) && ds.contains(y) && ds.same_set(x, y))
                cout << "-1\n";
            else
            {
                if (enemies.count(x))
                {
                    ds.join(enemies[x], y);
                    if (enemies.count(enemies[x]) && enemies.count(y))
                        ds.join(enemies[enemies[x]], enemies[y]);
                }
                else 
                    enemies[x] = y;
                
                if (enemies.count(y))
                {
                    ds.join(enemies[y], x);
                    if (enemies.count(enemies[y]) && enemies.count(x))
                        ds.join(enemies[enemies[y]], enemies[x]);
                }
                else 
                    enemies[y] = x;
            }
            break;
        case 3: // are friends
            if (x == y)
                cout << "1\n";
            else if (ds.contains(x) && ds.contains(y) && ds.same_set(x, y))
                cout << "1\n";
            else
                cout << "0\n";
            break;
        case 4: // are enemies  
            if (enemies.count(x) && ds.same_set(enemies[x], y))
                cout << "1\n";
            else if (enemies.count(y) && ds.same_set(enemies[y], x))
                cout << "1\n";
            else
                cout << "0\n";
        default:
            break;
        }
    }
    
    return 0;
}
