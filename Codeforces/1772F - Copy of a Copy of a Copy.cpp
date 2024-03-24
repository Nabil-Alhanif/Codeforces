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


int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, m, k;
    cin >> n >> m >> k;

    list<pair<vector<vector<char>>, ll>> ls;

    vector<vector<char>> cur(n, vector<char>(m));
    for (auto &i:cur) {
        for (auto &j:i)
            cin >> j;
    }
    ls.push_back({cur, 1});

    for (int i = 0; i < k; i++) {
        for (auto &r:cur) {
            for (auto &c:r)
                cin >> c;
        }

        bool depan;
        for (auto it = ls.begin(); it != ls.end(); ++it) {
            depan = 1;
            for (int r = 1; r < n - 1; r++) {
                for (int c = 1; c < m - 1; c++) {
                    if (cur[r][c] != (*it).fi[r][c])
                        depan &= cur[r][c] != cur[r - 1][c];
                }
            }
            if (depan) {
                ls.insert(it, {cur, i + 2});
                break;
            }
        }
        if (!depan)
            ls.push_back({cur, i + 2});
    }

    vector<string> ans;
    auto it = ls.begin();
    auto lst = ls.front();
    for (++it; it != ls.end(); ++it) {
        auto i = *it;
        for (int r = 1; r < n - 1; r++) {
            for (int c = 1; c < m - 1; c++) {
                if (i.fi[r][c] != lst.fi[r][c]) {
                    ans.push_back("1 " + to_string(r + 1) + " " + to_string(c + 1));
                }
            }
        }
        ans.push_back("2 " + to_string(i.se));
        lst = i;
    }

    cout << ls.front().se << "\n";
    cout << ans.size() << "\n";
    for (auto i:ans)
        cout << i << "\n";
}
