#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9+7, INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        ll a = n/3, b = n/3;
        n %= 3;

        if (n == 1)
            a++;
        else if (n == 2)
            b++;

        cout << a << " " << b << "\n";
    }
}
