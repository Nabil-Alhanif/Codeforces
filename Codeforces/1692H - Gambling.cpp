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


struct node
{
    ll l;
    ll r;
    ll val;
    ll choice;
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;

    while (t--) {
        ll n, x;
        cin >> n;

        node ans = {.val = 0};

        map<ll, node> m;
        for (int i = 0; i < n; i++) {
            cin >> x;

            // Kalau nggak ada artinya bikin baru
            if (m.find(x) == m.end()) {
                m[x] = {.l = i, .r = i, .val = 1, .choice = x};
                if (ans.val == 0)
                    ans = m[x];
            }
            else {
                // Kalau disatuin
                ll tmp = m[x].val + 1 - (i - m[x].r - 1);

                if (tmp > 0) {
                    m[x].r = i;
                    m[x].val = tmp;
                }
                else
                    m[x] = {.l = i, .r = i, .val = 1, .choice = x};

                if (ans.val < m[x].val)
                    ans = m[x];
            }
        }

        cout << ans.choice << " "  << ans.l + 1 << " " << ans.r + 1 << "\n";
    }
}
