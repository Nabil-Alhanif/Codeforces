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
inline T arithmeticSum(T a)
{
    return (((a * a) + a) / 2);
}

template <class T>
inline T arithmeticSum(T a, T b)
{
    return arithmeticSum(a) - arithmeticSum(b);
}
 
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
    fill(vect.begin(), vect.end(), vector<T>(m));
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

    int t, na, nb, nc;
    string s;

    cin >> t;
    while (t--) {
        cin >> s;

        na = 0, nb = 0, nc = 0;
        for (auto i:s) {
            if (i == 'A')
                na++;
            else if (i == 'B')
                nb++;
            else nc++;
        }

        if (nb == (na + nc))
            cout << "YES\n";
        else cout << "NO\n";
    }
}
