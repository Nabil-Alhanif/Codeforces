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

    string s;
    cin >> s;

    vector<set<ll>> data(26);
    ll size = s.size();
    for (int i = 0; i < size; i++)
        data[s[i] - 'a'].insert(i + 1);

    ll q;
    cin >> q;

    char c;
    ll type, l, r;
    while (q--) {
        cin >> type >> l;
        if (type == 1) {
            cin >> c;

            if (c == s[l - 1])
                continue;

            data[s[l - 1] - 'a'].erase(l);
            s[l - 1] = c;
            data[s[l - 1] - 'a'].insert(l);
        }
        else {
            cin >> r;

            ll ans = 0;
            for (int i = 0; i < 26; i++) {
                auto itr = data[i].lower_bound(l);
                if ((itr != data[i].end()) && (*itr <= r))
                    ans++;
            }
            cout << ans << "\n";
        }
    }
}
