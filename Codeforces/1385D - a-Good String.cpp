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

int search(string &s, char wanted, int leftBound, int rightBound)
{
    if (leftBound == rightBound)
        return (1 ^ (s[leftBound] == wanted));

    int half = (leftBound + rightBound) / 2;
    int size = (rightBound - leftBound + 1) / 2;

    int leftside = 0, rightside = 0;
    for (int i = leftBound; i <= half; i++) {
        if (s[i] == wanted)
            leftside++;
    }

    for (int i = half + 1; i <= rightBound; i++) {
        if (s[i] == wanted)
            rightside++;
    }

    return min(((size - leftside) + search(s, wanted + 1, half + 1, rightBound)),
               ((size - rightside) + search(s, wanted + 1, leftBound, half)));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t, size;
    string s;

    cin >> t;
    while (t--) {
        cin >> size >> s;
        cout << search(s, 'a', 0, size - 1) << "\n";
    }
}
