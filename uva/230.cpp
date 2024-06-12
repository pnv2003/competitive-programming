#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
#define ALL(x) x.begin(), x.end()

struct Book
{
    string name;
    string author;
};

int main(int argc, char const *argv[])
{
    auto book_order = [](Book b1, Book b2)
    {
        if (b1.author < b2.author)
            return true;
        if (b1.author > b2.author)
            return false;
        return (b1.name < b2.name);
    };
    vector<Book> shelf, borrowed, returned;
    string line;
    while (getline(cin >> ws, line))
    {
        if (line == "END") break;
        stringstream ss{ line };
        Book book;

        char dq;
        ss >> dq;
        getline(ss >> ws, book.name, dq);
        ss >> dq;

        ss >> book.author;
        getline(ss >> ws, book.author);
        shelf.push_back(book);
    }

    sort(ALL(shelf), book_order);
    while (getline(cin >> ws, line))
    {
        if (line == "END") break;
        stringstream ss{ line };

        string cmd, bookname;
        ss >> cmd;

        if (cmd == "BORROW")
        {
            char dq;
            ss >> dq;
            getline(ss >> ws, bookname, dq);
            ss >> dq;

            auto found = find_if(ALL(shelf), [&bookname](Book b){ return b.name == bookname; });
            borrowed.push_back(*found);
            shelf.erase(found);
        }
        else if (cmd == "RETURN")
        {
            char dq;
            ss >> dq;
            getline(ss >> ws, bookname, dq);
            ss >> dq;

            auto found = find_if(ALL(borrowed), [&bookname](Book b){ return b.name == bookname; });
            returned.push_back(*found);
            borrowed.erase(found);
        }
        else if (cmd == "SHELVE")
        {
            sort(ALL(returned), book_order);

            for (auto rit = returned.begin(); rit != returned.end(); ++rit)
            {
                auto pos = lower_bound(ALL(shelf), *rit, book_order);
                shelf.insert(pos, *rit);
                if (pos == shelf.begin())
                    cout << "Put \"" << rit->name << "\" first\n";
                else 
                    cout << "Put \"" << rit->name << "\" after \"" << (pos - 1)->name << "\"\n";
            }
            returned.clear();
            cout << "END\n";
        }
    }
    return 0;
}
