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

typedef complex<ll> pt;
#define X real()
#define Y imag()

const ll MOD = 1e9 + 7, INF = 1e15;
const double PI = acos(-1);


/* Question specific function and variable */

/* Note to self
 *
 * - Don't use a data structure when you don't need to
 * */


bool check(vector<vector<ll>> mat)
{
    if (mat[0][0] > mat[0][1])
        return 0;
    if (mat[0][0] > mat[1][0])
        return 0;
    if (mat[0][1] > mat[1][1])
        return 0;
    if (mat[1][0] > mat[1][1])
        return 0;
    return 1;
}

vector<vector<ll>> rotate(vector<vector<ll>> mat)
{
    vector<vector<ll>> ret(2, vector<ll>(2));
    ret[0][0] = mat[1][0];
    ret[0][1] = mat[0][0];
    ret[1][1] = mat[0][1];
    ret[1][0] = mat[1][1];
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;

    while (t--) {
        vector<vector<ll>> mat(2, vector<ll>(2));
        for (auto &i:mat) {
            for (auto &j:i)
                cin >> j;
        }

        bool bisa = 0;
        for (int i = 0; i < 4; i++) {
            mat = rotate(mat);
            bisa |= check(mat);
        }

        cout << (bisa ? "YES" : "NO") << "\n";
    }
}
