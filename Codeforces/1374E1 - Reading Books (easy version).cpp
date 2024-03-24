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

    ll k, n, t, a, b;
    cin >> n >> k;

    vector<ll> both, alice, bob;
    for (int i = 0; i < n; i++) {
        cin >> t >> a >> b;
        if (a && b)
            both.push_back(t);
        else if (a && !b)
            alice.push_back(t);
        else if (!a && b)
            bob.push_back(t);
    }

    sort(both.begin(), both.end());
    sort(alice.begin(), alice.end());
    sort(bob.begin(), bob.end());

    ll as = alice.size();
    ll bs = bob.size();

    ll both_size = both.size(), both_idx = 0;
    ll alice_size = alice.size(), alice_idx = 0;
    ll bob_size = bob.size(), bob_idx = 0;

    ll ans = 0, cnt;
    for (cnt = 0; cnt < k; cnt++) {
        if (both_idx < both_size) {
            if ((alice_idx < alice_size) && (bob_idx < bob_size)) {
                if ((alice[alice_idx] + bob[bob_idx]) < both[both_idx]) {
                    ans += (alice[alice_idx] + bob[bob_idx]);
                    alice_idx++, bob_idx++;
                }
                else {
                    ans += both[both_idx];
                    both_idx++;
                }
            }
            else {
                ans += both[both_idx];
                both_idx++;
            }
        }
        else {
            if ((alice_idx < alice_size) && (bob_idx < bob_size)) {
                ans += (alice[alice_idx] + bob[bob_idx]);
                alice_idx++, bob_idx++;
            }
            else break;
        }
    }

    cout << ((cnt < k) ? -1 : ans) << "\n";
}
