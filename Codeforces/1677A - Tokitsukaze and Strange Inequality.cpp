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

const ll MOD = 998244353, INF = 1e15;
const double PI = acos(-1);


/* Question specific function and variable */

/* Note to self
 *
 * - Don't use a data structure when you don't need to
 */


class fentree
{
    public:
        ll size;
        vector<ll> tree;

        fentree(){}

        void set(ll n)
        {
            this->size = n;
            this->tree.resize(n + 1);
        }

        ll get(ll idx)
        {
            if (idx < 0)
                return 0;

            ll ret = 0;
            for (; idx > 0; idx -= (idx & -idx))
                ret += this->tree[idx];
            return ret;
        }

        void add(ll idx)
        {
            for (; idx <= this->size; idx += (idx & -idx))
                this->tree[idx]++;
        }
};
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        vector<ll> arr(n);
        for (auto &i:arr)
            cin >> i;

        vector<fentree> pref(n + 1);
        fentree suff;

        pref[0].set(n);
        suff.set(n);

        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1];
            pref[i].add(arr[i - 1]);
        }

        ll ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            //cout << "C: " << arr[i] << "\n";
            for (int j = 0; j < i; j++) {
                //cout << "B: " << arr[j] << "\n";
                //cout << "nyari yang kecil dari b -> i: " << i << " arr[i] " << arr[i] << " cnt: " << suff.get(arr[j]) << "\n";
                //cout << "nyari yang kecil dari c -> j: " << j << " arr[j] " << arr[j] << " cnt: " << pref[j].get(arr[i]) << "\n";
                ans += (suff.get(arr[j]) * pref[j].get(arr[i]));
            }
            suff.add(arr[i]);
        }

        cout << ans << "\n";
    }
}
