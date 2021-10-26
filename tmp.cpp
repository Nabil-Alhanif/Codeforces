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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int tc, n, t, m, tt, ct, cnt = 0;
    bool pos;
    string p;

    cin >> tc;

    queue<pair<int, int>> kiri, kanan;

    while (tc--) {
        cin >> n >> t >> m;
        vector<int> ans(m);

        for (int i = 0; i < m; i++) {
            cin >> tt >> p;
            if (p == "left")
                kiri.push({i, tt});
            else kanan.push({i, tt});
        }

        ct = 0;
        pos = 0;
        cnt = 0;

        while (cnt < m) {
            if (!pos) {
                if (!kiri.empty()) {
                    ct = max(ct, kiri.front().se);
                    for (int i = 0; (i < n) && (!kiri.empty()); i++) {
                        if (kiri.front().se > ct)
                            break;

                        ans[kiri.front().fi] = ct + t;
                        kiri.pop();
                        cnt++;
                    }
                }
                else if (!kanan.empty())
                    ct = max(ct, kanan.front().se);
                ct += t;
                pos ^= 1;
            }
            else {
                if (!kanan.empty()) {
                    ct = max(ct, kanan.front().se);
                    for (int i = 0; (i < n) && (!kanan.empty()); i++) {
                        if (kanan.front().se > ct)
                            break;

                        ans[kanan.front().fi] = ct + t;
                        kanan.pop();
                        cnt++;
                    }
                }
                else if (!kiri.empty())
                    ct = max(ct, kiri.front().se);
                ct += t;
                pos ^= 1;
            }
        }

        for (auto i:ans)
            cout << i << "\n";

        if (tc)
            cout << "\n";
    }
}
