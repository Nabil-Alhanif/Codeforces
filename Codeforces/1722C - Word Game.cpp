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
        ll n, ansa = 0, ansb = 0, ansc = 0;
        cin >> n;

        map<string, ll> cnt;
        vector<string> a(n), b(n), c(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }

        for (int i = 0; i < n; i++) {
            cin >> b[i];
            cnt[b[i]]++;
        }

        for (int i = 0; i < n; i++) {
            cin >> c[i];
            cnt[c[i]]++;
        }

        for (int i = 0; i < n; i++) {
            if (cnt[a[i]] == 1)
                ansa += 3;
            else if (cnt[a[i]] == 2)
                ansa++;
        }

        for (int i = 0; i < n; i++) {
            if (cnt[b[i]] == 1)
                ansb += 3;
            else if (cnt[b[i]] == 2)
                ansb++;
        }

        for (int i = 0; i < n; i++) {
            if (cnt[c[i]] == 1)
                ansc += 3;
            else if (cnt[c[i]] == 2)
                ansc++;
        }

        cout << ansa << " " << ansb << " " << ansc << "\n";
    }
}
