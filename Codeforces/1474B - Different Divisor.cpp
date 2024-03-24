#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9 + 7, INF = 1e18;
const double PI = acos(-1);

vector<ll> f(400005);

inline void sieve(vector<bool> &vect, int lim = 1e6)
{
    vect[0] = 1;
    vect[1] = 1;

    for (int i = 2; i * i <= lim; i++)
    {
        for (int j = i * i; j <= lim; j += i)
            vect[j] = 1;
    }
}

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

    vector<bool> vect(1e6 + 1);
    sieve(vect, 1e6);

    vector<int>prime;
    for (int i = 2; i <= 1e6; i++)
    {
        if (!vect[i])
            prime.push_back(i);
    }

    ll t, d, ans = 0, size = prime.size();

    // Var for first binser
    ll l, r, mid;

    // Var for second binser
    ll lb, rb, mb;

    cin >> t;

    /*
    for (int i = 0; i < 10; i++)
        cout << prime[i] << "\n";
    */

    while (t--)
    {
        cin >> d;

        l = 0, r = size - 1, ans = INF;
        while (l <= r)
        {
            mid = (l + r) / 2;

            if (prime[mid] >= 1 + d)
            {
                //cout << prime[mid] << " " << r << "\n";
                lb = mid + 1, rb = size - 1;
                while (lb <= rb)
                {
                    mb = (lb + rb) / 2;
                    if (prime[mb] >= prime[mid] + d)
                    {
                        //cout << prime[mb] << " " << prime[mid] << "\n";
                        ans = min(ans, (ll)(((ll)prime[mb]) * ((ll)prime[mid])));
                        rb = mb - 1;
                    }
                    else lb = mb + 1;
                }

                r = mid - 1;
            }
            else l = mid + 1;
        }

        cout << ans << "\n";
    }
}
