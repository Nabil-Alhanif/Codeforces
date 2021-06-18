#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
ll INF = 1e18, MOD = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    
    while (t--)
    {
        int n, l, r;
        ll ans = 0;
        cin >> n >> l >> r;

        vector<ll> array(n);
        for (auto &i:array)
            cin >> i;
        sort(array.begin(), array.end());

        /*
        for (auto i:array)
            cout << i << " ";
        cout << "\n";
        */

        for (int i = 0; i < n; i++)
        {
            if (array[i] >= r)
                break;
            ll min_need = l - array[i];
            ll max_need = r - array[i];
            ll low = lower_bound(array.begin() + i, array.end(), min_need) - (array.begin());
            ll high = upper_bound(array.begin() + i, array.end(), max_need) - (array.begin());
            if (high > low)
            {
                ans += high - low;
                if (i == low)
                    ans--;
            }
            //cout << i << " " << low << " " << high << " " << min_need << " " << max_need << "\n";
        }
        cout << ans << "\n";
    }
}
