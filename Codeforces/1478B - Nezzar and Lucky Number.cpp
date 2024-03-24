#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7, inf = 1e13;
bool dp[207];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll q, d;
        cin >> q >> d;
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        if (!d)
            d += 10;
        for (int i=0; 10*i+d<=10*d; ++i)
            for (int j=0; 10*i+d+j<=10*d; ++j)
                dp[10*i+d+j] |= dp[j];
        while (q--)
        {
            int tmp;
            cin >> tmp;
            cout << ((tmp>=10*d || dp[tmp])?"YES\n":"NO\n");
        }
    }
}