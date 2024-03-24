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


class FenTree
{
    public:
        ll size;
        vector<ll> tree;

        FenTree(ll n)
        {
            this->size = n + 1;
            this->tree.resize(n + 1);
        }

        void add(ll idx, ll delta)
        {
            if (idx <= 0)
                return;

            for (; idx < this->size; idx += (idx & (-idx)))
                this->tree[idx] += delta;
        }

        ll get(ll idx)
        {
            if (idx <= 0)
                return 0;

            ll ret = 0;
            for (; idx > 0; idx -= (idx & (-idx)))
                ret += this->tree[idx];
            return ret;
        }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, k;
    cin >> n >> k;

    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<FenTree> data(k + 1, FenTree(n));

    /*
    for (int i = 0; i < n; i++)
        data[0].add(arr[i], 1);

    for (int i = 1; i <= k; i++) {
        cout << "Length: " << i << "\n";
        for (int j = 0; j < n; j++) {
            ll past = data[i - 1].get(arr[j] - 1);
            cout << arr[j] << " " << past << "\n";
            data[i].add(arr[j], past);
        }
        cout << "\n";
    }
    */

    for (int j = 0; j < n; j++) {
        data[0].add(arr[j], 1);
        for (int i = 1; i <= k; i++) {
            ll past = data[i - 1].get(arr[j] - 1);
            data[i].add(arr[j], past);
        }
    }

    /*
    for (int i = 0; i <= k; i++) {
        cout << "i: " << i << "\n";
        for (int j = 1; j <= n; j++)
            cout << data[i].tree[j] << " ";
        cout << "\n";
    }
    */

    cout << data[k].get(n) << "\n";
}
