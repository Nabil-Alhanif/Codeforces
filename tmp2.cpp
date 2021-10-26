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

string ans = "IMPOSSIBLE";
int n, m, k, pr, pc, len = 10;
vector<vector<bool>> vis;
vector<vector<char>> maze;

// Movement : DLRU
void dfs(int row, int col, int dist, string move)
{
    vis[row][col] = 1;
    //cout << row << " " << col << " " << dist << "\n";
    if (((row == pr) && (col == pc)) && (dist == k)) {
        //cout << move << "\n";
        if (dist < len) {
            ans = move;
            len = dist;
        }
        else ans = min(ans, move);
        return;
    }

    if (dist == k)
        return;

    // Down
    if (row + 1 < n) {
        if ((dist + 1 <= k) && (maze[row + 1][col] != '*')) {
            vis[row + 1][col] = 1;
            dfs(row + 1, col, dist + 1, move + 'D');
            vis[row + 1][col] = 0;
        }
    }

    // Left
    if (col - 1 >= 0) {
        if ((dist + 1 <= k) && (maze[row][col - 1] != '*')) {
            vis[row][col - 1] = 1;
            dfs(row, col - 1, dist + 1, move + 'L');
            vis[row][col - 1] = 0;
        }
    }

    // Right
    if (col + 1 < m) {
        if ((dist + 1 <= k) && (maze[row][col + 1] != '*')) {
            vis[row][col + 1] = 1;
            dfs(row, col + 1, dist + 1, move + 'R');
            vis[row][col + 1] = 0;
        }
    }

    // Up
    if (row - 1 >= 0) {
        if ((dist + 1 <= k) && (maze[row - 1][col] != '*')) {
            vis[row - 1][col] = 1;
            dfs(row - 1, col, dist + 1, move + 'U');
            vis[row - 1][col] = 0;
        }
    }

    return;
}

// Codeforces 769C
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;

    vis = vector<vector<bool>>(n, vector<bool>(m));
    maze = vector<vector<char>>(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 'X') {
                pr = i;
                pc = j;
            }
        }
    }

    /*
    for (auto i:maze) {
        for (auto j:i)
            cout << j << " ";
        cout << "\n";
    }
    */

    //cout << pr << " " << pc << " prpc\n";

    vis[pr][pc] = 1;
    dfs(pr, pc, 0, "");
    cout << ans << "\n";
}
