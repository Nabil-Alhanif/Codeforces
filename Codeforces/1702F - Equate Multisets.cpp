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
        ll n, x;
        cin >> n;

        multiset<ll> a, b;
        for (int i = 0; i < n; i++) {
            cin >> x;
            while (x % 2 == 0)
                x /= 2;
            a.insert(x);
        }

        for (int i = 0; i < n; i++) {
            cin >> x;
            b.insert(x);
        }

        /*
        for (auto i:a)
            cout << i << " ";
        cout << "\n";

        for (auto i:b)
            cout << i << " ";
        cout << "\n";
        */

        while (!b.empty() && !a.empty()) {
            ll last = *b.rbegin();

            if (last < *a.begin())
                break;

            if (a.count(last)) {
                a.erase(a.find(last));
                b.erase(b.find(last));
            }
            else {
                b.erase(b.find(last));
                b.insert(last / 2);
            }
        }

        cout << (b.empty() ? "YES\n" : "NO\n");
    }
}
