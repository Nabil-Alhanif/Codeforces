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

const ll MOD = 1e8, INF = 1e15;
const double PI = acos(-1);


/* Question specific function and variable */

/* Note to self
 *
 * - Don't use a data structure when you don't need to
 */


struct segment
{
    ll val;
    ll next;
    ll prev;
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;

    map<ll, ll> pos;

    vector<segment> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].val;
        arr[i].next = -1;
        arr[i].prev = -1;
        pos[arr[i].val] = i;
    }

    for (int i = 0; i < n; i++) {
        if (pos.find(arr[i].val * 2) != pos.end()) {
            ll p = pos[arr[i].val * 2];
            arr[i].next = p;
            arr[p].prev = i;
        }
        if (arr[i].val % 3 == 0) {
            if (pos.find(arr[i].val / 3) != pos.end()) {
                ll p = pos[arr[i].val / 3];
                arr[i].next = p;
                arr[p].prev = i;
            }
        }
    }

    segment root;
    for (auto i:arr) {
        if (i.prev == -1)
            root = i;
    }

    do {
        cout << root.val << " ";
        if (root.next == -1)
            break;
        root = arr[root.next];
    } while (1);
    cout << "\n";
}
