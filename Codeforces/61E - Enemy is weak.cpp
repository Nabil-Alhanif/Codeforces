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

typedef long double ld;
typedef int_fast64_t ll;
typedef uint_fast64_t ull;
typedef __uint128_t u128_t;
typedef __int128_t i128_t;

template <typename T>
using pt = complex<T>;
#define X real()
#define Y imag()

const ll MOD = 1e9 + 7, INF = 1e15;
const double PI = acos(-1);


/* Question specific function and variable */

/* Note to self
 *
 * - Don't use a data structure when you don't need to
 * */


class FenwickTree
{
    public:
        ll size;
        vector<ll> tree;

        FenwickTree(ll n)
        {
            this->size = n + 1;
            this->tree.resize(this->size);
        }

        void add(ll idx, ll val)
        {
            for(; idx < this->size; idx += idx & -idx)
                this->tree[idx] += val;
        }

        ll query(ll idx)
        {
            ll sum = 0;
            for (; idx > 0; idx -= idx & -idx)
                sum += this->tree[idx];
            return sum;
        }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;

    map<ll, ll> cnt;
    vector<ll> arr(n), pos(n);
    FenwickTree pref(n), suff(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        pos[i] = arr[i];
    }

    sort(pos.begin(), pos.end());
    for (int i = 0; i < n; i++)
        cnt[pos[i]] = i + 1;

    for (int i = 0; i < n; i++) {
        arr[i] = cnt[arr[i]];
        suff.add(arr[i], 1);
    }
    reverse(arr.begin(), arr.end());

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll kecil = pref.query(arr[i]);
        pref.add(arr[i], 1);

        ll besar = n - i - suff.query(arr[i]);
        suff.add(arr[i], -1);

        //cout << kecil << " " << besar << "\n";
        ans += (kecil * besar);
    }
    cout << ans << "\n";
}
