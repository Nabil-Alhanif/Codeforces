#include <cstdint>
#include <iostream>
typedef int_fast32_t ll;

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    int t;
    std::cin >> t;
    
    while (t--)
    {
        ll a, b, k;
        std::cin >> a >> b >> k;

        if (k == 0)
        {
            if (a == b)
                std::cout << "YES\n";
            else std::cout << "NO\n";
            continue;
        }

        if (k == 1)
        {
            if ((a!=b)&&((a%b==0)||(b%a==0)))
                std::cout << "YES\n";
            else std::cout << "NO\n";
            continue;
        }

        ll fact_a = 0;
        ll fact_b = 0;

        for (int i = 2; i*i <= a; i++)
        {
            while (a%i==0)
            {
                a/=i;
                fact_a++;
            }
        }
        if (a > 1)
            fact_a++;

        for (int i = 2; i*i <= b; i++)
        {
            while (b%i==0)
            {
                b/=i;
                fact_b++;
            }
        }
        if (b > 1)
            fact_b++;

        if (k <= (fact_a+fact_b))
            std::cout << "YES\n";
        else std::cout << "NO\n";
    }
}
