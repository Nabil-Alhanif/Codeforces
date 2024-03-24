#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define P10_UINT64 10000000000000000000ULL   /* 19 zeroes */
#define E10_UINT64 19
 
#define fi first
#define se second
 
using namespace std;
using namespace __gnu_pbds;
 
template <typename T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag,
      tree_order_statistics_node_update>;
 
typedef int_fast64_t ll;
typedef uint_fast64_t ull;
typedef __uint128_t u128_t;
typedef __int128_t i128_t;
 
const ll MOD = 998244353, INF = 1e18;
const double PI = acos(-1);


/* Question specific function and variable */

/* Note to self
 *
 * - Don't use a data structure when you don't need to
 */


class FenwickTree
{
    public:
        vector<ll> bit;
        ll size;

        FenwickTree(ll n) {
            this->size = n;
            bit.assign(n, 0);
        }

        ll get(ll idx) {
            if (idx < 0)
                return 0;

            ll ret = 0;
            for (; idx > 0; idx -= (idx & -idx))
                ret += this->bit[idx];
            return ret;
        }

        ll get(ll l, ll r) {
            ll ret;
            ret = this->get(r) - this->get(l);
            return ret;
        }

        void add(ll idx) {
            for (; idx < this->size; idx += (idx & -idx))
                this->bit[idx]++;
        }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        ll n, a, ans = 0;
        cin >> n;

        FenwickTree fentree(n + 1);

        vector<pair<ll, ll>> arr;
        for (int i = 1; i <= n; i++) {
            cin >> a;
            if (a < i)
                arr.push_back({a, i});
        }

        for (auto itr = arr.rbegin(); itr != arr.rend(); ++itr) {
            //cout << (*itr).fi << " " << (*itr).se << "\n";
            ans += fentree.get((*itr).se, n);
            if ((*itr).fi != 0)
                fentree.add((*itr).fi);
        }

        cout << ans << "\n";
    }
}
