#include <algorithm>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second

using namespace std;
using namespace __gnu_pbds;

typedef int_fast64_t ll;
typedef uint_fast64_t ull;

const ll INF = 1e9 + 7;

int main()
{
    ll n, ans = 0, mins = INF, mp;
    cin >> n;

    vector<ll> asli(n);
    for (int i = 0; i < n; i++) {
        cin >> asli[i];
        if (asli[i] < mins) {
            mins = asli[i];
            mp = i + 1;
        }
    }

    vector<ll> arr(mp);
    for (int i = 0, j = mp - 1; (i < mp) && (j >= 0); i++, j--) {
        arr[i] = asli[j];
    }

    /*
    vector<vector<ll>> diff(n, vector<ll>(n, INF));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            diff[i][j] = arr[i] - arr[j];
            if (j > 0)
                diff[i][j] += diff[i][j - 1];
        }
    }
    */
    vector<ll> pref(mp);
    pref[0] = arr[0];
    for (int i = 1; i < mp; i++)
        pref[i] = pref[i - 1] + arr[i];

    /*
    for (auto i:diff) {
        for (auto j:i)
            cout << j << " ";
        cout << "\n";
    }
    */

    vector<ll> dp(mp, INF);
    dp[0] = 0;
    for (int i = 1; i < mp; i++) {
        dp[i] = (arr[i] * (i + 1) - pref[i]);
        for (int j = i - 2; j > 0; j--)
            dp[i] = min(dp[i], (arr[i] * (i + 1) - pref[i]) - (arr[i] * (j + 1) - pref[j]) + dp[j]);
    }

    /*
    for (auto i:dp)
        cout << i << " ";
    cout << "\n";
    */

    ans = dp[mp - 1];

    ll sisa = n - mp;
    vector<ll> ars(sisa);
    for (int i = 0, j = mp + 1; (i < sisa) && (j < n); i++, j++) {
        ars[i] = asli[j];
    }

    vector<ll> suff(sisa);
    suff[0] = ars[0];
    for (int i = 1; i < sisa; i++)
        suff[i] = suff[i - 1] + ars[i];

    /*
    for (auto i:diff) {
        for (auto j:i)
            cout << j << " ";
        cout << "\n";
    }
    */

    vector<ll> dp2(sisa, INF);
    dp2[0] = 0;
    for (int i = 1; i < sisa; i++) {
        dp2[i] = (ars[i] * (i + 1) - suff[i]);
        for (int j = i - 2; j > 0; j--)
            dp2[i] = min(dp2[i], (ars[i] * (i + 1) - suff[i]) - (ars[i] * (j + 1) - suff[j]) + dp2[j]);
    }

    ans += dp2[sisa - 1];
    cout << ans << "\n";
}
