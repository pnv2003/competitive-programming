#include <iostream>
using namespace std;
using ll = long long;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main(int argc, char const *argv[])
{
    FASTIO;
    for (ll a = 1; a < 500; ++a)
    {
        for (ll b = a; b < 667; ++b)
        {
            for (ll c = b; c < 1000; ++c)
            {
                auto num = 1000000*(a + b + c);
                auto den = a*b*c - 1000000;
                if (den <= 0 || num % den != 0) continue;
                ll d = num / den;
                if (d < c) continue;

                ll sum = a+b+c+d, prod = a*b*c*d;
                if (sum > 2000) continue;
                if (sum*1000000 == prod)
                    printf("%.2lf %.2lf %.2lf %.2lf\n", a*0.01, b*0.01, c*0.01, d*0.01);
            }
        }
    }
    return 0;
}
