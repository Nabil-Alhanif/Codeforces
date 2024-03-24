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


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    // Ni kode bakal jelek sih gaes, tapi yaudah lah ya
    // a = 1 -> 2
    // b = 2 -> 3
    // c = 3 -> 1
    ll t, n, a, b, c, cur, last, start, mid, end, fdist, sdist, tdist, dst, mp, pf, ps, pt, pd;
    cin >> t;

    while (t--) {
        cin >> n >> a >> b >> c;
        if ((a >= b) && (a >= c)) {
            start = 1;
            end = 2;
            mid = 3;
            fdist = a;
            sdist = c;
            tdist = b;
        }
        else if ((b >= a) && (b >= c)) {
            start = 2;
            end = 3;
            mid = 1;
            fdist = b;
            sdist = a;
            tdist = c;
        }
        else if ((c >= a) && (c >= b)) {
            start = 3;
            end = 1;
            mid = 2;
            fdist = c;
            sdist = b;
            tdist = a;
        }
        else {
            cout << "NO\n";
            continue;
        }

        dst = sdist + tdist;
        dst -= fdist;

        if ((dst % 2) || (dst < 0)) {
            cout << "NO\n";
            continue;
        }

        dst /= 2;

        vector<pair<ll, ll>> ans;

        pf = fdist - 1;
        ps = sdist - 1;
        pt = tdist - 1;
        pd = max(dst - 1, (ll)0);

        last = start;
        cur = 4;

        for (int i = pd; i < ps; i++, cur++) {
            ans.push_back({last, cur});
            last = cur;
        }

        mp = last;

        for (int i = 0; i < pd; i++, cur++) {
            ans.push_back({last, cur});
            last = cur;
        }

        ans.push_back({last, mid});

        last = mp;
        if (dst == 0)
            last = mid;
        else pd++;

        for (int i = pd; i < pt; i++, cur++) {
            ans.push_back({last, cur});
            last = cur;
        }

        ans.push_back({last, end});
        last = end;

        for (; cur <= n; cur++) {
            ans.push_back({last, cur});
            last = cur; 
        }

        ll maks = 0;
        for (auto i:ans) {
            maks = max(maks, i.fi);
            maks = max(maks, i.se);
        }

        if (maks > n) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        //cout << "start: " << start << " end: " << end << " mid: " << mid << " fdist: " << fdist << " sdist: " << sdist << " tdist: " << tdist << " dst: " << dst << "\n";
        for (auto i:ans)
            cout << i.fi << " " << i.se << "\n";
    }
}
