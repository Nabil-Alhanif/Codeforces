#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll INF = 1e13, MOD = 1e9+7;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, ans = 0;
        cin >> n;
        vector<int> ar(n);
        for (int i=0; i<n; i++)
            cin >> ar[i];
        int cur = ar[0];
        for (int i=1; i<n; i++)
        {
            cur = ar[i-1];
            while (min(ar[i], cur)*2 < max(ar[i], cur))
            {
                ans++;
                if (ar[i]<=cur)
                    cur = (int)ceil(((double)cur)/2);
                else
                    cur*=2;
                //cout << ar[i] << " " << ar[i-1] << " " << cur << "\n";
            }
        }
        cout << ans << "\n";
    }
}
