#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7, inf = 1e13;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, d;
        cin >> n >> d;
        int ar[n];
        bool gede = 0;
        for (int i=0; i<n; i++)
            cin >> ar[i], gede |= ar[i]>d;
        sort(ar, ar+n);
        if (ar[0]+ar[1]<=d||!gede)
            cout << "YES\n";
        else cout << "NO\n";
    }
}