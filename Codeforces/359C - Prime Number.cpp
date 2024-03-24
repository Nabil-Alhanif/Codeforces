#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define P10_UINT64 10000000000000000000ULL /* 19 zeroes */
#define E10_UINT64 19

#define fi first
#define se second

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using indexed_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef int_fast64_t ll;
typedef uint_fast64_t ull;
typedef __uint128_t u128_t;
typedef __int128_t i128_t;

const ll MOD = 1e9 + 7, INF = 1e15;
const double PI = acos(-1);


/* Question specific function and variable */

/* Note to self
 *
 * - Don't use a data structure when you don't need to
 * */


ll fastExp(ll base, ll pow)
{
    if (pow <= 0)
        return 1;
    if (pow == 1)
        return (base % MOD);

    ll half = fastExp(base, pow / 2);
    if (pow % 2)
        return ((half * half) % MOD * base) % MOD;
    return (half * half) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, x, sum = 0;
    cin >> n >> x;

    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    for (int i = 0; i < n; i++)
        arr[i] = sum - arr[i];
    sort(arr.begin(), arr.end(), greater<ll>());

    ll ans;
    while (1) {
        ll last = arr.back(), cnt = 1;
        arr.pop_back();

        while ((arr.size()) && (arr.back() == last)) {
            cnt++;
            arr.pop_back();
        }

        //cout << last << " " << cnt << "\n";

        if (cnt % x) {
            last = min(last, sum);
            ans = fastExp(x, last) % MOD;
            break;
        }
        else {
            cnt /= x;
            for (int i = 0; i < cnt; i++)
                arr.push_back(last + 1);
        }
    }

    cout << ans << "\n";
}
