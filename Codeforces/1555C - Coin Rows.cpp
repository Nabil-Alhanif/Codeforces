#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define P10_UINT64 10000000000000000000ULL /* 19 zeroes */
#define E10_UINT64 19

#define fi first
#define se second

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using indexed_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef int_fast64_t ll;
typedef uint_fast64_t ull;
typedef __uint128_t u128_t;
typedef __int128_t i128_t;

const ll MOD = 1e9 + 7, INF = 1e15;
const double PI = acos(-1);


/* Question specific function and variable */

/* Note to self
 *
 * - Don't use a data structure when you don't need to
 * */

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;

    while (t--) {
        ll m;
        cin >> m;

        vector<ll> pref(m + 2), suff(m + 2);
        vector<vector<ll>> board(2, vector<ll>(m));

        for (auto &i:board) {
            for (auto &j:i)
                cin >> j;
        }

        for (int i = 1; i <= m; i++)
            pref[i] = pref[i - 1] + board[1][i - 1];
        for (int i = m; i > 0; i--)
            suff[i] = suff[i + 1] + board[0][i - 1];

        ll ans = INF;
        for (int i = 1; i <= m; i++)
            ans = min(ans, max(pref[i - 1], suff[i + 1]));
        cout << ans << "\n";
    }
}
