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

    ll t, n, k, l, tide, cnt;
    bool down, flag;

    cin >> t;
    while (t--) {
        cnt = 0;
        cin >> n >> k >> l;

        vector<ll> depth(n + 5);
        vector<ll> safe;

        safe.push_back(0);
        for (int i = 1; i <= n; i++) {
            cin >> depth[i];
            if (depth[i] + k <= l)
                safe.push_back(i);
        }
        safe.push_back(n + 1);
        cnt = safe.size();

        flag = 1;
        for (int i = 1; i < cnt; i++) {
            tide = k;
            down = 1;
            for (int j = safe[i - 1] + 1; j < safe[i]; j++) {
                if (down)
                    tide--;
                else tide++;

                //cout << tide << " " << depth[j] << " td\n";
                // Check if we should have wait more
                if (down)
                    tide -= max((ll)0, (depth[j] + tide - l));

                if ((tide < 0) || (depth[j] + tide > l)) {
                    flag = 0;
                    break;
                }

                if (tide == 0)
                    down = 0;
            }
        }

        if (flag)
            cout << "Yes\n";
        else cout << "No\n";
    }
    //adfasdf
}
