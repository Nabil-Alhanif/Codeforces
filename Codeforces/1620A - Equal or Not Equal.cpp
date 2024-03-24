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


/* Question specific function and variable */

/* Note to self
 *
 * - Don't use a data structure when you don't need to
 */


struct DSU
{
    int size;
    vector<int> parent;

    DSU(int n)
    {
        this->size = n;
        this->parent.resize(n);

        for (int i = 0; i < n; i++)
            this->parent[i] = i;
    }

    int find(int x)
    {
        if (this->parent[x] == x)
            return x;
        return (this->parent[x] = find(this->parent[x]));
    }

    void combine(int x, int y)
    {
        x = find(x);
        y = find(y);

        if (x != y)
            this->parent[x] = y;
    }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int size = s.size();
        DSU yaDSU(size);

        for (int i = 0; i < size; i++) {
            if (s[i] == 'E')
                yaDSU.combine(i, (i + 1) % size);
        }

        bool ans = 1;
        for (int i = 0; i < size; i++) {
            if (s[i] == 'N')
                ans &= (yaDSU.find(i) != yaDSU.find((i + 1) % size));
        }

        cout << (ans ? "YES\n" : "NO\n");
    }
}
