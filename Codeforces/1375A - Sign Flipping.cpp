#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> ar(n);
        for (int i=0; i<n; i++)
        {
            cin >> ar[i];
            ar[i] = abs(ar[i]);
            if (i%2)
                cout << -ar[i] << " ";
            else cout << ar[i] << " ";
        }
        cout << "\n";
    }
}
