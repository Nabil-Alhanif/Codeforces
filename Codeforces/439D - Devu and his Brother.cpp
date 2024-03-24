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

template <typename T>
using pt = complex<T>;
#define X real()
#define Y imag()

const ll MOD = 1e9 + 7, INF = 1e15;
const double PI = acos(-1);


/* Question specific function and variable */

/* Note to self
 *
 * - Don't use a data structure when you don't need to
 * */


ll n, m;
vector<ll> a, b, prefa, prefb;

ll check(ll cur)
{
    //cout << "CHECKING " << cur << "!\n";
    ll pa = -1;
    for (ll l = 0, r = n - 1, mid = (l + r) / 2; l <= r; mid = (l + r) / 2) {
        if (a[mid] < cur) {
            pa = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    ll ca = 0;
    if (pa != -1)
        ca = (pa + 1) * cur - prefa[pa];
    //cout << ca << "\n";

    ll pb = -1;
    for (ll l = 0, r = m - 1, mid = (l + r) / 2; l <= r; mid = (l + r) / 2) {
        if (b[mid] > cur) {
            pb = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    ll cb = 0;
    if (pb != -1)
        cb = prefb[pb] - (m - pb) * cur;
    //cout << cb << "\n";

    return (ca + cb);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    a.resize(n);
    b.resize(m);
    prefa.resize(n);
    prefb.resize(m);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    prefa[0] = a[0];
    for (int i = 1; i < n; i++)
        prefa[i] = prefa[i - 1] + a[i];

    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(b.begin(), b.end());

    prefb[m - 1] = b[m - 1];
    for (int i = m - 2; i >= 0; i--) 
        prefb[i] = prefb[i + 1] + b[i];

    if (a[0] >= b[m - 1])
        return cout << "0\n", 0;

    ll ans = INF;
    for (ll l = a[0], r = b[m - 1], m1 = l + (r - l) / 3, m2 = r - (r - l) / 3; l <= r; m1 = l + (r - l) / 3, m2 = r - (r - l) / 3) {
        ll pm1 = check(m1);
        ll pm2 = check(m2);

        //cout << l << " " << r << " " << m1 << " " << m2 << " " << pm1 << " " << pm2 << "\n";

        ans = min(ans, min(pm1, pm2));
        if (pm1 <= pm2)
            r = m2 - 1;
        else l = m1 + 1;
    }

    cout << ans << "\n";
}
