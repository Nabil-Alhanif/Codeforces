#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9+7, INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, k, a, ans = 0, satu = 0;
    cin >> n >> k;

    vector<ll> drink(k);

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        drink[--a]++;
    }

    for (int i = 0; i < k; i++)
    {
        ans += drink[i] / 2;
        if (drink[i] % 2)
            satu++;
    }
    
    cout << (ans * 2) + ((satu + 1) / 2) << "\n";
}
