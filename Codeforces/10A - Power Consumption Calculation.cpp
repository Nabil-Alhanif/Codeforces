#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define P10_UINT64 10000000000000000000ULL   /* 19 zeroes */
#define E10_UINT64 19
 
#define fi first
#define se second
 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int, null_type, less<int>, rb_tree_tag,
            tree_order_statistics_node_update> indexed_set;
 
typedef int_fast64_t ll;
typedef uint_fast64_t ull;
typedef __uint128_t u128_t;
typedef __int128_t i128_t;
 
const ll MOD = 1e9 + 7, INF = 1e18;
const double PI = acos(-1);
 
template <class T>
inline T ceil(T a, T b) // Get ceil of a / b
{
    if (b > 0)
        return ((a + b - 1) / b);
    return 0;
}
 
template <class T>
inline void printVect2D(vector<vector<T>> &vect)
{
    for (auto i:vect) {
        for (auto j:i)
            cout << j << " ";
        cout << "\n";
    }
    cout << "\n";
}
 
template <class T>
inline void printVect1D(vector<T> &vect)
{
    for (auto i:vect)
        cout << i << " ";
    cout << "\n";
}
 
static void print_u128_u(u128_t u128)
{
    if (u128 > UINT64_MAX)
    {
        u128_t leading  = u128 / P10_UINT64;
        ull trailing = u128 % P10_UINT64;
        print_u128_u(leading);
        cout << trailing;
    }
    else
    {
        ull u64 = u128;
        cout << u64;
    }
}

/* Question specific function and variable */

/* Note to self
 *
 * - Don't use a data structure when you don't need to
 */

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, p1, p2, p3, t1, t2, ans = 0, dif;
    cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;

    vector<pair<int, int>> time(n);
    for (auto &i:time)
        cin >> i.fi >> i.se;

    for (int i = 0; i < n - 1; i++) {
        time[i].se = min(time[i].se + t1, time[i + 1].fi);
        ans += p1 * (time[i].se - time[i].fi);
        //cout << (time[i].se - time[i].fi) << "\n";

        dif = time[i + 1].fi - time[i].se;
        ans += p2 * min(dif, t2);
        //cout << min(dif, t2) << "\n";

        dif = max(0, dif - t2);
        ans += p3 * dif;
        //cout << dif << "\n";
    }
    ans += p1 * (time[n - 1].se - time[n - 1].fi);

    cout << ans << "\n";
}
