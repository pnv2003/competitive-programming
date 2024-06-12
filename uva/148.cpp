#include <iostream>
#include <cctype>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
#define ALL(x) x.begin(), x.end()

int main(int argc, char const *argv[])
{
    vector<string> dict, sdict;
    string word;
    while (cin >> word)
    {
        if (word == "#") 
            break;
        dict.push_back(word);
    }

    string sent, sent_cont;
    vector<string> sent_words, ana_words;
    while (getline(cin >> ws, sent))
    {
        if (sent == "#") 
            break;

        sent_cont = sent;
        auto sclast = remove_if(ALL(sent_cont), [](char c){ return !isalpha(c); });
        sent_cont.erase(sclast, sent_cont.end());

        stringstream ss{ sent };
        while (ss >> word)
            sent_words.push_back(word);
        set_difference(ALL(dict), ALL(sent_words), sdict);

        sort(sent_cont.begin(), sent_cont.end());
        


    }
    
    
    return 0;
}
