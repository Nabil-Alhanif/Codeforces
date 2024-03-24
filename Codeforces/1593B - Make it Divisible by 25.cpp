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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t, size, p0, p5;
    string s;

    cin >> t;
    while (t--) {
        p0 = -1, p5 = -1;

        cin >> s;
        size = s.size();

        for (int i = size; i >= 0; i--) {
            if (s[i] == '0') {
                if (p0 == -1)
                    p0 = i;
                else {
                    cout << size - (i + 2) << "\n";
                    break;
                }
            }
            else if (s[i] == '5') {
                if (p0 != -1) {
                    cout << size - (i + 2) << "\n";
                    break;
                }
                if (p5 == -1)
                    p5 = i;
            }
            else if (s[i] == '2') {
                if (p5 != -1) {
                    cout << size - (i + 2) << "\n";
                    break;
                }
            }
            else if (s[i] == '7') {
                if (p5 != -1) {
                    cout << size - (i + 2) << "\n";
                    break;
                }
            }
        }
    }
}
