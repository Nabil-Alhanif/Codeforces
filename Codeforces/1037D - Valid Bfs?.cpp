#include <bits/stdc++.h>
#include <ctime>
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

struct dat
{
    int idx;
    int parent;

    dat(){}

    dat(int pos, int par)
    {
        this->idx = pos;
        this->parent = par;
    }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, x, y, size;
    cin >> n;

    vector<vector<int>> adjList(n);
    for (size_t i = 0; i < n - 1; i++) {
        cin >> x >> y;
        x--, y--;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }

    vector<int> arr(n);
    for (auto &i:arr) {
        cin >> i;
        i--;
    }

    if (arr[0] != 0)
        return cout << "No\n", 0;

    vector<int> parent(n, -1);
    int ptr = 0;

    queue<int> bfs;
    bfs.push(0);
    parent[0] = 0;

    while (!bfs.empty()) {
        x = bfs.front();
        bfs.pop();

        for (auto i:adjList[x]) {
            if (parent[i] == -1) {
                parent[i] = x;
                bfs.push(i);
            }
        }
    }

    queue<dat> q;
    q.push({0, 0});

    dat tmp;
    while (!q.empty()) {
        tmp = q.front();
        q.pop();

        if (parent[tmp.idx] != tmp.parent)
            return cout << "No\n", 0;

        size = adjList[tmp.idx].size();
        if (tmp.idx != 0)
            size--;

        for (int i = ptr + 1; i <= ptr + size; i++)
            q.push({arr[i], tmp.idx});
        ptr += size;
    }

    return cout << "Yes\n", 0;
}
