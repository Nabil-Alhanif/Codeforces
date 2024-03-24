#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9+7, INF = 1e18;

ll d(pair<int, int> a, pair<int, int> b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        ll n, ans = 0;
        cin >> n;
        
        vector<ll> arr(n);
        for (auto &i:arr)
            cin >> i;

        for (ll i = 0; i < n; i++)
        {
            for (ll j = i; j < n; j++)
            {
                if ( i + 2 <= j)
                {
                    bool bisa = 1;
                    for (ll h = i; h < j; h++)
                    {
                        for (ll k = h + 1; k < j; k++)
                        {
                            if (d({arr[h], h}, {arr[j], j}) == d({arr[h], h}, {arr[k], k}) + d({arr[k], k}, {arr[j], j}))
                                bisa = 0;
                        }
                    }

                    if (!bisa)
                        break;
                }
                ans++;
            }
        }
        
        cout << ans << "\n";
    }
}
