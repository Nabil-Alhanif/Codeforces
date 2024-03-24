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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, sl = 0, dl = 0, ml = 0, tmp;
    bool flag = 1, fnd = 0, tm;

    cin >> n;

    vector<int> arr(n);
    vector<int> cnt(101);

    for (auto &i:arr) {
        cin >> i;
        cnt[i]++;
    }

    for (int i = 1; i <= 100; i++) {
        if (cnt[i] == 1)
            sl++;
        else if (cnt[i] == 2)
            dl++;
        else if (cnt[i] > 2)
            ml++;
    }

    if (sl % 2)
        flag = (ml > 0);

    if (flag)
        cout << "YES\n";
    else return cout << "NO\n", 0;

    vector<bool> ans(n);
    tmp = 0;
    fnd = 0;
    for (int i = 0; i < n; i++) {
        //cout << arr[i] << " " << fnd << " " << tmp << "\n";

        if (cnt[arr[i]] == 1) {
            ans[i] = tmp % 2;
            tmp++;
        }
        else if ((cnt[arr[i]] > 2) && (sl % 2 == 1)) {
            if (!fnd) {
                fnd = 1;
                ans[i] = tmp % 2;
                tm = tmp % 2;
                tmp++;
            }
            else ans[i] = !tm;
        }
    }

    for (auto i:ans)
        cout << (i ? 'A' : 'B');
    cout << "\n";
}
