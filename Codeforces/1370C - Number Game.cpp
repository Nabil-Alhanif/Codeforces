#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9 + 7, INF = 1e18;
const double PI = acos(-1);

vector<ll> f(400005);

ll inv(ll base, ll mod)
{
    if (base == 1)
        return 1;
    return inv(mod % base, mod) * (mod - (mod / base)) % mod;
}

ll comb(ll a, ll b)
{
    ll aa = f[a], bb = inv(f[b], MOD), cc = inv(f[a-b], MOD);
    aa *= bb;
    aa %= MOD;
    aa *= cc;
    aa %= MOD;
    return aa;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        if (n == 1)
            cout << "FastestFinger\n";
        else if (n == 2)
            cout << "Ashishgup\n";
        else
        {
            if (n % 2)
                cout << "Ashishgup\n";
            else
            {
                int cnt = 0;
                while (n % 2 == 0)
                {
                    cnt++;
                    n /= 2;
                }

                bool prime = 1;
                for (int i = 2; i * i <= n; i++)
                {
                    if (n % i == 0)
                    {
                        prime = 0;
                        break;
                    }
                }

                if ((n == 1) || ((cnt == 1) && prime))
                    cout << "FastestFinger\n";
                else cout << "Ashishgup\n";
            }
        }
    }
}
