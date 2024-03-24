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


bool comp(pair<ll, ll> &a, pair<ll, ll> &b)
{
    return (a.se < b.se);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;

    while (t--) {
        string s;
        ll p, tot = 0;

        cin >> s >> p;

        ll n = s.size();
        vector<pair<ll, ll>> arr(n);

        for (int i = 0; i < n; i++) {
            arr[i] = {s[i] - 'a' + 1, i};
            tot += arr[i].fi;
        }
        sort(arr.begin(), arr.end());

        ll pos = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (tot <= p) {
                pos = i;
                break;
            }
            tot -= arr[i].fi;
        }
        sort(arr.begin(), arr.begin() + pos + 1, comp);

        for (int i = 0; i <= pos; i++) {
            //cout << arr[i].se << " " << arr[i].fi << "\n";
            cout << s[arr[i].se];
        }
        cout << "\n";
    }
}
