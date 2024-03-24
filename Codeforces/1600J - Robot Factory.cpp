#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds//tree_policy.hpp>

#define P10_UINT64 10000000000000000000ULL   /* 19 zeroes */
#define E10_UINT64 19

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
            tree_order_statistics_node_update> indexed_set;

typedef int_fast64_t ll;
typedef __uint128_t u128_t;
typedef __int128_t i128_t;

const ll MOD = 1e9 + 7, INF = 1e18;
const double PI = acos(-1);

template <class type>
inline void printVect2D(vector<vector<type>> &vect)
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

    ll lim = vect.size() - 1;
 
    for (ll i = 2; i * i <= lim; i++) {
        if (!vect[i]) {
            for (ll j = i * i; j <= lim; j += i)
                vect[j] = 1;
        }
    }
}

inline vector<int> sieve(vector<bool> &vect)
{
    vector<int> ret;

    ll size = vect.size();
    for (ll i = 0; i <= size; i++) {
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

// Codeforces 1600J

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m, r, c, g, group = 0;
    cin >> n >> m;

    vector<vector<bool>> vis(n + 2, vector<bool>(m + 2));
    vector<vector<int>> factory(n + 2, vector<int>(m + 2));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cin >> factory[i][j];
    }

    for (int i = 0; i < n + 2; i++) {
        vis[i][0] = 1;
        vis[i][m + 1] = 1;
    }

    for (int i = 0; i < m + 2; i++) {
        vis[0][i] = 1;
        vis[n + 1][i] = 1;
    }

    /*
    for (auto i:vis) {
        for (auto j:i)
            cout << j << " ";
        cout << "\n";
    }
    */

    map<int, int> ma;
    queue<pair<pair<int, int>, int>> q;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            //cout << (factory[i][j] & (1 << 3)) << " " << (factory[i][j] & (1 << 2)) << " " << (factory[i][j] & (1 << 1)) << " " << (factory[i][j] & (1 << 0)) << "\n";
            if (!vis[i][j]) {
                q.push({{i, j}, group});
                vis[i][j] = 1;

                while (!q.empty()) {
                    r = q.front().first.first;
                    c = q.front().first.second;
                    g = q.front().second;
                    ma[g]++;
                    q.pop();

                    //cout << r << " " << c << "\n";

                    if (!(factory[r][c] & (1 << 3)) && !vis[r - 1][c]) {
                        vis[r - 1][c] = 1;
                        q.push({{r - 1, c}, g});
                    }
                    if (!(factory[r][c] & (1 << 2)) && !vis[r][c + 1]) {
                        vis[r][c + 1] = 1;
                        q.push({{r, c + 1}, g});
                    }
                    if (!(factory[r][c] & (1 << 1)) && !vis[r + 1][c]) {
                        vis[r + 1][c] = 1;
                        q.push({{r + 1, c}, g});
                    }
                    if (!(factory[r][c] & (1 << 0)) && !vis[r][c - 1]) {
                        vis[r][c - 1] = 1;
                        q.push({{r, c - 1}, g});
                    }
                }
                //cout << "\n\n";

                group++;
            }
        }
    }

    vector<int> ans;
    for (auto i:ma)
        ans.push_back(i.second);
    sort(ans.begin(), ans.end(), greater<int>());
    
    for (auto i:ans)
        cout << i << " ";
    cout << "\n";
}
