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
        bool bisa = 0;
        cin >> n;
        for (int i = 0; i*2020<=n; i++)
        {
            if ((n-i*2020)%2021==0)
            {
                cout << "YES\n";
                bisa = 1;
                break;
            }
        }
        if (!bisa)
            cout << "NO\n";
    }
}