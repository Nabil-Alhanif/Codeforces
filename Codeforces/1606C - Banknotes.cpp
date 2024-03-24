#include <bits/stdc++.h>

using namespace std;

typedef int_fast64_t ll;

const ll MOD = 1e9 + 7, INF = 1e18;
const double PI = acos(-1);


/* Question specific function and variable */

/* Note to self
 *
 * - Don't use a data structure when you don't need to
 */

int main()
{
    ll t, n, k;

    cin >> t;
    while (t--) {
        cin >> n >> k;
        k++;
        vector<ll> ans(10), den(n);

        for (auto &i:den)
            cin >> i;

        for (int i = 0; i < n - 1; i++) {
            ans[den[i]] = min(k, (ll)(pow(10, den[i + 1] - den[i]) - 1));
            k -= ans[den[i]];
        }
        ans[den[n - 1]] = max((ll)0, k);

        for (int i = 9; i >= 0; i--) {
            if (ans[i])
                cout << ans[i];
        }
        cout << "\n";
    }
}
