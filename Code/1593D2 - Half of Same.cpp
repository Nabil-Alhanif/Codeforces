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

    int t, n, tmp, ans;

    cin >> t;
    while (t--) {
        ans = -1;
        cin >> n;

        map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            cnt[tmp]++;
        }

        for (auto i = cnt.begin(); i != cnt.end(); i++) {
            if ((*i).se >= (n / 2)) {
                ans = -1;
                break;
            }

            map<int, int> dif, div_count;

            auto j = i;
            for (j++; j != cnt.end(); j++)
                dif[abs((*i).fi - (*j).fi)] += (*j).se;

            for (auto k:dif) {
                for (int v = 1; v * v <= k.fi; v++) {
                    if (k.fi % v == 0) {
                        div_count[v] += k.se;
                        if (v * v != k.fi)
                            div_count[k.fi / v] += k.se;
                    }
                }
            }

            for (auto k:div_count) {
                if ((*i).se + k.se >= (n / 2))
                    ans = max(ans, k.fi);
            }
        }

        cout << ans << "\n";
    }
}
