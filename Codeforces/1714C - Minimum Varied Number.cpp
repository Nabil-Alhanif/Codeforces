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

const ll MOD = 998244353, INF = 1e18;
const double PI = acos(-1);


/* Question specific function and variable */

/* Note to self
 *
 * - Don't use a data structure when you don't need to
 */


map<ll, vector<ll>> dp;

void generate(int idx, int total, vector<ll> con)
{
    if (dp.find(total) != dp.end())
        return;

    sort(con.begin(), con.end());
    dp[total] = con;
    for (int i = idx - 1; i > 0; i--) {
        con.push_back(i);
        generate(i, total + i, con);
        con.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    generate(10, 0, *(new vector<ll>));

    ll t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        vector<ll> ans = dp[n];
        for (auto i:ans)
            cout << i;
        cout << "\n";
    }
}
