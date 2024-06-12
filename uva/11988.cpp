#include <iostream>
#include <string>
#include <list>
using namespace std;

int main(int argc, char const *argv[])
{
    string line;
    while (getline(cin >> ws, line))
    {
        list<char> beiju;

        list<char>::iterator cursor = beiju.end();
        for (char c: line)
        {
            if (c == '[') 
                cursor = beiju.begin();
            else if (c == ']')
                cursor = beiju.end();
            else 
            {
                cursor = beiju.insert(cursor, c);
                ++cursor;
            }
        }

        for (char c: beiju)
            cout << c;
        cout << "\n";
    }
    
    return 0;
}
