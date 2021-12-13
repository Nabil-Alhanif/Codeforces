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

inline void sieve(vector<bool> &vect, bool is_one_prime)
{
    vect[0] = 1;
    if (!is_one_prime)
        vect[1] = 1;

    int_fast32_t lim = vect.size() - 1;
 
    for (int_fast32_t i = 2; i * i <= lim; i++) {
        if (!vect[i]) {
            for (ll j = i * i; j <= lim; j += i)
                vect[j] = 1;
        }
    }
}

inline vector<int> sieve(vector<bool> &vect)
{
    vector<int> ret;

    int_fast32_t size = vect.size();
    for (int_fast32_t i = 0; i <= size; i++) {
        if (!vect[i])
            ret.push_back(i);
    }

    return ret;
}


/* Question specific function and variable */

/* Note to self
 *
 * - Don't use a data structure when you don't need to
 */

vector<ll> cnt;
vector<ll> parent;
vector<ll> arr;
vector<bool> state;

ll find(ll u)
{
    if (parent[u] != u)
        return find(parent[u]);
    return u;
}

void combine(ll u, ll v)
{
    ll pu = find(u), pv = find(v);

    if (pu == pv)
        return;

    parent[pv] = pu;
    cnt[pu] += cnt[pv];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, u, v, last;
    cin >> n;

    // Initialize global variable
    cnt = vector<ll>(n);
    arr = vector<ll>(n);
    parent = vector<ll>(n);

    state = vector<bool>(n);

    vector<ll> query(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        cnt[i] = 0;
        parent[i] = i;
    }

    for (auto &i:query) {
        cin >> i;
        i--;
    }

    vector<ll> ans(n);
    ans[n - 1] = 0;
    u = query[n - 1];
    state[u] = 1;
    cnt[u] = arr[u];
    last = arr[u];

    for (int i = n - 2; i >= 0; i--) {
        /*
        for (auto i:cnt)
            cout << i << " ";
        cout << "\n";
        */

        v = query[i + 1];
        u = query[i];
        last = max(last, cnt[find(v)]);
        ans[i] = last;

        state[u] = 1;
        cnt[u] = arr[u];

        if (u > 0) {
            if (state[u - 1])
                combine(u, u - 1);
        }
        if (u < n - 1) {
            if (state[u + 1])
                combine(u, u + 1);
        }
    }

    for (auto i:ans)
        cout << i << "\n";
}
