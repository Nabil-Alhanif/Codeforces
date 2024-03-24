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

static void print_u128_u(u128_t u128)
{
    if (u128 > UINT64_MAX)
    {
        u128_t leading  = u128 / P10_UINT64;
        uint_fast64_t  trailing = u128 % P10_UINT64;
        print_u128_u(leading);
        cout << trailing;
    }
    else
    {
        uint_fast64_t u64 = u128;
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

    int t, n, k, u, v, x, ans;
    cin >> t;

    while (t--) {
        ans = 0;
        cin >> n >> k;

        vector<vector<int>> adj_list(n);
        vector<int> layer(n);
        vector<int> con(n);

        for (int i = 1; i < n; i++) {
            cin >> u >> v;
            --u, --v;
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
            con[v]++;
            con[u]++;
        }

        /*
        for (int i = 0; i < n; i++) {
            cout << i + 1 << ": ";
            for (auto j:adj_list[i])
                cout << j + 1 << " ";
            cout << "\n";
        }
        */

        // current node, depth
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            if (adj_list[i].size() <= 1) { // This node is a leaf
                q.push({i, 1});
                layer[i] = 1;
            }
        }

        while (!q.empty()) {
            u = q.front().fi;
            x = q.front().se;
            q.pop();

            for (auto i:adj_list[u]) {
                if (layer[i] == 0) { // Not yet visited
                    con[i]--;
                    if (con[i] <= 1) {
                        q.push({i, x + 1});
                        layer[i] = x + 1;
                    }
                }
            }
        }

        for (auto i:layer) {
            if (i > k)
                ans++;
        }

        cout << ans << "\n";
    }
}
