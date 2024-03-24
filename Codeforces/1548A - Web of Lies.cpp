#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <queue>

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

const ll MOD = 1e8, INF = 4e18;
const double PI = acos(-1);


/* Question specific function and variable */

/* Note to self
 *
 * - Don't use a data structure when you don't need to
 */


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, m, u, v, cnt = 0;
    cin >> n >> m;

    vector<ll> size(n), weaker(n);
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        u--, v--;
        size[u]++;
        size[v]++;
        weaker[max(u, v)]++;
    }

    ll q, t;
    cin >> q;

    vector<bool> same(n);
    for (int i = 0; i < n; i++) {
        if (weaker[i] == size[i]) {
            same[i] = 1;
            cnt++;
        }
    }

    while (q--) {
        cin >> t;

        if (t == 1) {
            cin >> u >> v;
            u--, v--;
            size[u]++;
            size[v]++;
            weaker[max(u, v)]++;

            if (same[u] && (weaker[u] != size[u])) {
                same[u] = 0;
                cnt--;
            }
            else if (!same[u] && (weaker[u] == size[u])) {
                same[u] = 1;
                cnt++;
            }

            if (same[v] && (weaker[v] != size[v])) {
                same[v] = 0;
                cnt--;
            }
            else if (!same[v] && (weaker[v] == size[v])) {
                same[v] = 1;
                cnt++;
            }
        }
        else if (t == 2) {
            cin >> u >> v;
            u--, v--;
            size[u]--;
            size[v]--;
            weaker[max(u, v)]--;

            if (same[u] && (weaker[u] != size[u])) {
                same[u] = 0;
                cnt--;
            }
            else if (!same[u] && (weaker[u] == size[u])) {
                same[u] = 1;
                cnt++;
            }

            if (same[v] && (weaker[v] != size[v])) {
                same[v] = 0;
                cnt--;
            }
            else if (!same[v] && (weaker[v] == size[v])) {
                same[v] = 1;
                cnt++;
            }
        }
        else cout << cnt << "\n";
    }
}
