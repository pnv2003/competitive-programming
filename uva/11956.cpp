#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    int t, id = 1;
    cin >> t;

    string code;
    while (t--)
    {
        int arr[100]{};
        for (int i = 0; i < 100; ++i)
            arr[i] = 0;
        int* ptr = arr;
        int* ptr_end = ptr + 99;

        cin >> code;   
        cout << "Case " << id++ << ": ";
        for (char c: code)
        {
            switch (c)
            {
            case '>':
                if (ptr == ptr_end) 
                    ptr = arr;
                else 
                    ++ptr;
                break;
            case '<':
                if (ptr == arr) 
                    ptr = ptr_end;
                else 
                    --ptr;
                break;
            case '+':
                ++(*ptr);
                if (*ptr == 256) 
                    *ptr = 0;
                break;
            case '-':
                if (*ptr == 0) 
                    *ptr = 255;
                else 
                    --(*ptr);
                break;
            case '.':
                // printf("%02X", *ptr);
                break;
            default:
                break;
            }
        }

        for (int i = 0; i < 100; ++i) {
            printf("%02X", arr[i]);
            if (i != 99)
                cout << " ";
            else
                cout << "\n";
        }
    }
    return 0;
}
