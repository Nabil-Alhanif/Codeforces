#include <bits/stdc++.h>
typedef int_fast64_t ll;
using namespace std;
ll INF = 1e18, MOD = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    
    while (t--)
    {
        int n;
        ll ans = 0;
        cin >> n;
        ll ar[n+1];
        for (int i = 1; i <= n; i++)
            cin >> ar[i];

        for (int i = 1; i <= n; i++)
        {
            ll value = ar[i];
            ll rem = i % value;
            if (rem)
                rem = value - rem;
            else rem = value;
            for (int j = rem; j <= n; j += value)
            {
                if ((i != j) && (i + j == value * ar[j]))
                {
                    //cout << value << " " << ar[j] << " " << i << " " << j << "\n";
                    ans++;
                }
            }
        }

        cout << ans/2 << "\n";
    }
}
