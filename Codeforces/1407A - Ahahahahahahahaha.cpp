#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
ll INF = 1e18, MOD = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, satu = 0, dua = 0;
        cin >> n;
        vector<ll> ar(n);
        for (auto &i:ar)
        {
            cin >> i;
            if (i==1)
                satu++;
            else dua++;
        }
        if (satu <= n/2)
        {
            cout << dua << "\n";
            for (int i=0; i<dua; i++)
                cout << "0 ";
            cout << "\n";
        }
        else
        {
            satu -= satu%2;
            cout << satu << "\n";
            for (int i=0; i<satu; i++)
                cout << "1 ";
            cout << "\n";
        }
    }
}
