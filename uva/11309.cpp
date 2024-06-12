#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef struct
{
    int hour;
    int minute;
} clock_t_;

void clock_next(clock_t_& clock)
{
    if (clock.minute == 59)
    {
        clock.minute = 0;
        if (clock.hour == 23)
            clock.hour = 0;
        else
            ++clock.hour;
    }
    else
        ++clock.minute;
}

string clock_string(clock_t_ clock)
{
    if (clock.hour == 0)
        return to_string(clock.minute);
    return 
    (
        to_string(clock.hour) +
        (clock.minute < 10 ? "0" : "") + 
        to_string(clock.minute)
    );
}

bool isPalindrome(const string& str)
{
    string revstr = str;
    reverse(revstr.begin(), revstr.end());
    if (str == revstr)
        return true;
    return false;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    while (n--)
    {
        string time;
        cin >> time;
        clock_t_ clock 
        {
            stoi(time.substr(0, 2)), 
            stoi(time.substr(3, 2))
        };
        do 
        {
            clock_next(clock);
        }
        while (!isPalindrome(clock_string(clock)));

        printf("%02d:%02d\n", clock.hour, clock.minute);
    }
    return 0;
}
