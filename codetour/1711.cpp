#include <cstdio>
using namespace std;
using ull = unsigned long long;
int main(int argc, char const *argv[])
{
    ull n;
    scanf(" %llu", &n);
    printf("%llu\n", ((n*n*n + n) / 2ULL) % 2027ULL);
    return 0;
}
