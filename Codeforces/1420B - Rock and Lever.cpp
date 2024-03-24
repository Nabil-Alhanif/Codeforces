#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9 + 7, INF = 1e18;
const double PI = acos(-1);

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

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int t, n;
    ll ans, cnt;
    cin >> t;

    while (t--)
    {
        cin >> n;
        ans = 0;

        vector<int> ar(n);
        for (auto &i:ar)
            cin >> i;

        for (int i = 29; i>= 0; i--)
        {
            cnt = 0;

            for (auto j:ar)
                cnt += (ll)((j >= (1 << i)) && (j < (1 << (i + 1))));

            ans += (cnt * (cnt - 1)) / 2;
        }

        cout << ans << "\n";
    }
}
