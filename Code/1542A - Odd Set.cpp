#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9+7, INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;

    while (t--)
    {
        int n, odds = 0;
        cin >> n;

        vector<int> sets(2*n);
        for (auto &i:sets)
        {
            cin >> i;
            odds += (i%2);
        }

        if (odds == n)
            cout << "Yes\n";
        else cout << "No\n";
    }
}
