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

const ll MOD = 998244353, INF = 1e18;
const double PI = acos(-1);


/* Question specific function and variable */

/* Note to self
 *
 * - Don't use a data structure when you don't need to
 */


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll q;
    cin >> q;

    while (q--) {
        ll n;
        string t;
        cin >> t >> n;

        ll tsize = t.size();

        vector<string> subs(n);
        for (auto &i:subs)
            cin >> i;

        vector<ll> length(n);
        vector<pair<pair<ll, ll>, ll>> data; // start, end, type
        for (int i = 0; i < n; i++) {
            size_t pos = -1;
            length[i] = subs[i].length();
            do {
                pos = t.find(subs[i], pos + 1);
                if (pos != string::npos)
                    data.push_back({{pos, pos + length[i] - 1}, i + 1});
                else break;
            }
            while (pos != string::npos);
        }

        sort(data.begin(), data.end());

        vector<ll> dp(tsize, 1e9);
        vector<ll> type(tsize, -1);
        for (auto i:data) {
            //cout << "start: " << i.fi.fi << " end: " << i.fi.se << " type: " << i.se << "\n";
            //cout << dp[i.fi.se] << " " << type[i.fi.fi] << "\n";
            if (i.fi.fi < dp[i.fi.se]) {
                if (i.fi.fi < dp[i.fi.fi])
                    dp[i.fi.fi] = i.fi.fi;
                dp[i.fi.se] = i.fi.fi;
                type[i.fi.fi] = i.se;
            }
            //cout << dp[i.fi.se] << " " << type[i.fi.fi] << "\n";
        }

        bool bisa = 1;

        /*
        for (int i = 0; i < tsize; i++) {
            cout << "i: " << i << " start: " << dp[i] << " type: " << type[i] << "\n";
        }
        */

        ll pos = -1;
        for (int i = tsize - 1; i >= 0; i--) {
            //cout << "i:" << i << " pos: " << pos << "\n";
            if (i < pos)
                pos = -1;

            if ((pos == -1) && (dp[i] != 1e9))
                pos = dp[i];
            pos = min(pos, dp[i]);
            dp[i] = pos;

            bisa &= (dp[i] != -1);
        }

        ll cur_type = -1;
        for (int i = 0; i < tsize; i++) {
            if (type[i] == -1)
                type[i] = cur_type;
            else cur_type = type[i];
        }

        /*
        for (int i = 0; i < tsize; i++) {
            cout << "i: " << i << " start: " << dp[i] << " type: " << type[i] << "\n";
        }
        */

        if (!bisa) {
            cout << "-1\n";
            continue;
        }

        vector<pair<ll, ll>> ans;
        for (ll pos = tsize - 1; pos >= 0; ) {
            ans.push_back({type[dp[pos]], dp[pos] + 1});
            pos = dp[pos] - 1;
        }

        cout << ans.size() << "\n";
        for (auto i:ans)
            cout << i.fi << " " << i.se << "\n";
    }
}
