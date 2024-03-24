#include <algorithm>
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

const ll MOD = 1e9 + 7, INF = 1e15;
const double PI = acos(-1);


/* Question specific function and variable */

/* Note to self
 *
 * - Don't use a data structure when you don't need to
 * */


vector<vector<ll>> combinatoric(1001, vector<ll>(1001));

void count_combinatoric()
{
    // Base case
    for (int i = 0; i <= 1000; i++)
        combinatoric[i][0] = 1;
 
    for (int i = 1; i <= 1000; i++)
    {
        for (int j = 1; j <= 1000; j++)
            combinatoric[i][j] = ((combinatoric[i-1][j-1] % MOD) + (combinatoric[i-1][j] % MOD)) % MOD;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    count_combinatoric();

    ll n, m, k;
    cin >> n >> m >> k;

    map<pair<ll, ll>, short> col;

    vector<pair<ll, ll>> blocktm;

    for (int i = 0; i < k; i++) {
        ll r, c;
        cin >> r >> c;
        r--, c--;
        blocktm.push_back({r - 1, r + 1});

        col[{r, c}] = 0;
        col[{r, c - 1}] = 0;
        col[{r, c + 1}] = 0;
        col[{r - 1, c}] = 0;
        col[{r - 1, c - 1}] = 0;
        col[{r - 1, c + 1}] = 0;
        col[{r + 1, c}] = 0;
        col[{r + 1, c - 1}] = 0;
        col[{r + 1, c + 1}] = 0;
    }
    sort(blocktm.begin(), blocktm.end());

    vector<pair<ll, ll>> block;
    if (k != 0) {
        ll st = blocktm[0].fi;
        ll en = blocktm[0].se;

        for (auto i:blocktm) {
            if (i.fi <= en)
                en = i.se;
            else {
                block.push_back({st, en});
                st = i.fi;
                en = i.se;
            }
        }
        block.push_back({st, en});
    }

    ll ans = 0;

    ll lp = 0;
    vector<ll> start(m), last(m);

    for (int j = 1; j < m; j++) {
        if (col.find({0, j}) != col.end())
            continue;
        start[j] = start[j - 1];
    }

    for (auto i:block) {
        cout << i.fi << " " << i.se << "\n";

        ll st = (i.fi < 5 ? 0 : i.fi);
        ll si = (i.fi < 5 ? i.se + 1 : i.se - i.fi);
        vector<vector<ll>> board(si, vector<ll>(m));

        if (i.fi > 5) {
            // Generate dulu posisi terakhirnya
            while (lp + 100 <= st) {
                lp += 100;
                last[0] = start[0];
                for (int i = 1; i < m; i++) {

                }
            }
        }

        ll norm = st;
        for (int i = st + 1; i <= si; i++) {
            for (int j = 0; j < m; j++) {
                //
            }
        }
        lp = si;
    }

    cout << ans << "\n";
}
