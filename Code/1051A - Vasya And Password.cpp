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

template <class T>
inline void printVect1D(vector<T> &vect)
{
    for (auto i:vect)
        cout << i << " ";
    cout << "\n";
}


/* Question specific function and variable */

/* Note to self
 *
 * - Don't use a data structure when you don't need to
 */

bool check(string s)
{
    int ret = 0;
    for (auto i:s) {
        if ((i >= '0') && (i <= '9'))
            ret |= 1;
        else if ((i >= 'a') && (i <= 'z'))
            ret |= 2;
        else ret |= 4;
    }
    return (ret == 7);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    string s;
    bool flag;
    char c;

    cin >> t;
    while (t--) {
        flag = 0;

        cin >> s;

        if (check(s)) {
            cout << s << "\n";
            continue;
        }

        for (auto &i:s) {
            c = i;

            i = '1';
            if (check(s)) {
                cout << s << "\n";
                flag = 1;
                break;
            }

            i = 'a';
            if (check(s)) {
                cout << s << "\n";
                flag = 1;
                break;
            }

            i = 'A';
            if (check(s)) {
                cout << s << "\n";
                flag = 1;
                break;
            }

            i = c;
        }

        if (!flag) {
            s[0] = 'A';
            s[1] = 'a';
            if (check(s)) {
                cout << s << "\n";
                continue;
            }

            s[1] = '1';
            if (check(s)) {
                cout << s << "\n";
                continue;
            }

            s[0] = 'a';
            cout << s << "\n";
        }
    }
}
