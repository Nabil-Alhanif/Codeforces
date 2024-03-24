#include <algorithm>
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

typedef long double ld;
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


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t;
	cin >> t;

	while (t--) {
		ll n, m, d, pp = 1;
		cin >> n >> m >> d;

		vector<ll> seller_tmp(m);
		for (auto &i:seller_tmp)
			cin >> i;

		vector<ll> seller(1);
		seller[0] = 1;
		for (int i = (seller_tmp[0] == 1 ? 1 : 0); i < m; i++)
			seller.push_back(seller_tmp[i]);
		m = seller.size();

		vector<vector<ll>> dp(m, vector<ll>(2));
		dp[0][0] = 1;
		dp[0][1] = 1;
		for (int i = 1; i < m; i++) {
			ll dif = seller[i] - seller[i - 1];
			dp[i][0] = dp[i - 1][0] + (dif - 1) / d + 1;
			ll a = (dp[i - 1][1] + (dif - 1) / d + 1);
			ll b = (dp[i - 1][0] + dif / d);
			if (b < a)
		}

		ll ans = dp[m - 1][1] + (n - seller[m - 1]) / d;
		cout << ans << "\n";

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < m; j++)
				cout << dp[j][i] << " ";
			cout << "\n";
		}
	}
}
