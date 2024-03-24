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
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<pair<pair<ll, ll>, ll>> que(q);

    for (auto &i:que)
        cin >> i.fi.fi >> i.fi.se >> i.se;

    vector<pair<pair<ll, ll>, ll>> fin_queue;
    vector<ll> beg(n);
    for (int i = 0; i < n; i++)
        beg[i] = -1;

    //cout << "QUE\n";
    for (auto i:que) {
        //cout << i.fi.fi << " " << i.fi.se << " " << beg[i.fi.fi] << "\n";

        // Ini coba ilangin semua sorting yang sepenuhnya masuk ke sorting sekarang
        while ((!fin_queue.empty()) && ((fin_queue.back().fi.fi >= i.fi.fi) && (fin_queue.back().fi.se <= i.fi.se)))
            fin_queue.pop_back();

        while ((!fin_queue.empty()) && ((((i.fi.fi >= fin_queue.back().fi.fi) && (i.fi.fi <= fin_queue.back().fi.se)) || ((i.fi.se >= fin_queue.back().fi.fi) && (i.fi.se <= fin_queue.back().fi.se))) && (i.se == fin_queue.back().se))) {
            i.fi.fi = min(i.fi.fi, fin_queue.back().fi.fi);
            i.fi.se = max(i.fi.se, fin_queue.back().fi.se);
            fin_queue.pop_back();
        }

        fin_queue.push_back(i);
    }

    //cout << "FIN_QUE\n";
    for (auto i:fin_queue) {
        //cout << i.fi.fi << " " << i.fi.se << " " << i.se << "\n";
        if (i.se == 0)
            sort(s.begin() + i.fi.fi - 1, s.begin() + i.fi.se, greater<char>());
        else sort(s.begin() + i.fi.fi - 1, s.begin() + i.fi.se);

        //cout << l << " " << r << " " << s << "\n";
    }

    cout << s << "\n";
}
