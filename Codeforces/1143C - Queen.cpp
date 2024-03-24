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

    ll n, p, c;
    cin >> n;

    vector<vector<ll>> children(n);
    vector<bool> disrespect(n);

    for (int i = 0; i < n; i++) {
        cin >> p >> c;
        disrespect[i] = c;

        if (p != -1)
            children[p - 1].push_back(i);
    }

    vector<ll> ans;
    for (int i = 0; i < n; i++) {
        if (disrespect[i]) {
            bool del = 1;
            for (auto j:children[i])
                del &= disrespect[j];
            if (del)
                ans.push_back(i + 1);
        }
    }

    if (ans.empty())
        cout << -1;
    for (auto i:ans)
        cout << i << " ";
    cout << "\n";
}
