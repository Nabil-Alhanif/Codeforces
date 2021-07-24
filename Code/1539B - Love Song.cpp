#include <bits/stdc++.h>
typedef int_fast64_t ll;
using namespace std;
ll INF = 1e18, MOD = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, q;
    char c;
    cin >> n >> q;

    vector<ll> count(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> c;
        count[i] = count[i-1] + (c - 'a' + 1);
    }

    int l, r;
    while (q--)
    {
        cin >> l >> r;
        cout << count[r] - count[l-1] << "\n";
    }
}
