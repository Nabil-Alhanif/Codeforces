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
        int n;
        cin >> n;

        vector<ll> ar(2*n);

        for (auto &i:ar)
            cin >> i;
        sort(ar.begin(), ar.end());

        for (int i = 0; i < n; i++)
            cout << ar[i] << " " << ar[i+n] << " ";
        cout << "\n";
    }
}
