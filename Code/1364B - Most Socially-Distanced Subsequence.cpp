#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
            tree_order_statistics_node_update> indexed_set;

typedef int_fast64_t ll;
const ll MOD = 1e9 + 7, INF = 1e18;
const double PI = acos(-1);

template <class type>
inline void printVect2D(vector<vector<type>> &vect)
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

    ll lim = vect.size() - 1;
 
    for (ll i = 2; i * i <= lim; i++) {
        if (!vect[i]) {
            for (ll j = i * i; j <= lim; j += i)
                vect[j] = 1;
        }
    }
}

inline vector<int> sieve(vector<bool> &vect)
{
    vector<int> ret;

    ll size = vect.size();
    for (ll i = 0; i <= size; i++) {
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

    int t, n, pos;
    cin >> t;

    while (t--) {
        cin >> n;

        vector<int> arr(n);
        vector<int> dp(n);
        vector<int> ans;

        for (auto &i:arr)
            cin >> i;
        dp[1] = 0;

        for (int i = 2; i < n; i++) {
            if ((arr[i] < arr[i - 1]) && (arr[i - 1] < arr[i - 2]))
                dp[i] = dp[i - 1];
            else if ((arr[i] > arr[i - 1]) && (arr[i - 1] > arr[i - 2]))
                dp[i] = dp[i - 1];
            else dp[i] = i - 1;
        }

        /*
        for (auto i:dp)
            cout << i << " ";
        cout << "\n";
        */

        pos = n - 1;
        while (1) {
            ans.push_back(arr[pos]);

            if (pos == 0)
                break;

            pos = dp[pos];
        }
        reverse(ans.begin(), ans.end());

        cout << ans.size() << "\n";
        for (auto i:ans)
            cout << i << " ";
        cout << "\n";
    }
}
