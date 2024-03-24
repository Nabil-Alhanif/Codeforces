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

const ll MOD = 1e9 + 7, INF = LLONG_MAX;
const double PI = acos(-1);


/* Question specific function and variable */

/* Note to self
 *
 * - Don't use a data structure when you don't need to
 * */


ll n, a, r, m;
vector<ll> arr, pref;

ll check(ll cur)
{
    // Cari dulu jumlah yang nggak nyampe cur
    ll cnt = 0;
    for (ll l = 0, r = n - 1, mid = (l + r) / 2; l <= r; mid = (l + r) / 2) {
        if (arr[mid] < cur) {
            cnt = mid + 1;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    ll needed = 0;
    if (cnt > 0)
        needed = cnt * cur - pref[cnt - 1];

    ll lebih = n - cnt;
    ll over = pref[n - 1] - (cnt ? pref[cnt - 1] : 0) - ((n - cnt) * cur);

    //cout << cur << " " << cnt << " " << needed << " " << over << "\n";

    ll ret = 0;

    // Jadi, mindahin itu untuk jika:
    // Mindahin lebih murah daripada ngambil & ngilangin
    m = min(m, a + r);

    // Oke sekarang kita pindahin
    ll transfer = min(needed, over);
    ret += m * transfer;
    needed = max((ll)0, needed - transfer);
    over = max((ll)0, over - transfer);

    ret += a * needed;
    ret += r * over;

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> a >> r >> m;

    arr.resize(n);
    pref.resize(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());

    pref[0] = arr[0];
    for (int i = 1; i < n; i++)
        pref[i] = pref[i - 1] + arr[i];


    ll ans = INF;
    for (ll l = arr[0], r = arr[n - 1], m1 = l + (r - l) / 3, m2 = r - (r - l) / 3; l <= r; m1 = l + (r - l) / 3, m2 = r - (r - l) / 3) {
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
