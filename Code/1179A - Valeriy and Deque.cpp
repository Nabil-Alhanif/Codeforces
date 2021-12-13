#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define P10_UINT64 10000000000000000000ULL   /* 19 zeroes */
#define E10_UINT64 19
 
#define fi first
#define se second
 
using namespace std;
using namespace __gnu_pbds;
 
template <typename T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag,
      tree_order_statistics_node_update>;

typedef int_fast64_t ll;
typedef uint_fast64_t ull;
typedef __uint128_t u128_t;
typedef __int128_t i128_t;
 
const ll MOD = 1e9 + 7, INF = 1e18;
const double PI = acos(-1);
 
template <class T>
inline void printVect1D(vector<T> &vect)
{
    for (auto i:vect)
        cout << i << " ";
    cout << "\n";
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
inline void resizeVect1D(vector<T> &vect, int n)
{
    vect.resize(n);
}
 
template <class T>
inline void resizeVect2D(vector<vector<T>> &vect, int n, int m)
{
    vect.resize(n);
    for (auto &i:vect)
        i.resize(m);
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

    ll n, q, m, u, v, maks = 0;
    cin >> n >> q;

    deque<ll> dq;
    for (size_t i = 0; i < n; i++) {
        cin >> m;
        maks = max(maks, m);
        dq.push_back(m);
    }

    vector<pair<ll, size_t>> query(q);
    for (size_t i = 0; i < q; i++) {
        cin >> query[i].fi;
        query[i].fi--;
        query[i].se = i;
    }
    sort(query.begin(), query.end());

    vector<pair<ll, ll>> ans(q);

    size_t pos, cnt;
    for (pos = 0, cnt = 0; pos < q; cnt++) {
        if (dq.front() == maks)
            break;

        u = dq.front();
        dq.pop_front();
        v = dq.front();
        dq.pop_front();

        dq.push_front(max(u, v));
        dq.push_back(min(u, v));

        while (query[pos].fi == cnt) {
            ans[query[pos].se] = {u, v};
            pos++;
        }
    }

    vector<ll> arr(n - 1);
    dq.pop_front();
    for (size_t i = 0; i < n - 1; i++) {
        arr[i] = dq.front();
        dq.pop_front();
    }

    for (; pos < q; pos++) {
        query[pos].fi -= cnt;
        ans[query[pos].se] = {maks, arr[query[pos].fi % (n - 1)]};
    }

    /*
    cout << "Vect: ";
    for (auto i:arr)
        cout << i << " ";
    cout << "\n";
    */

    for (auto i:ans)
        cout << i.fi << " " << i.se << "\n";
}
