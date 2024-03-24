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


bool check_prime(ll n)
{
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}

ll PFS(ll n)
{
	// Case kalau 1
	if (n <= 1)
		return 0;

	// Case kalau prima
	if (check_prime(n))
		return 1;

	// Itung buat semua yang lain
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			ll dif = n / i;
			return PFS(i) + PFS(dif);
		}
	}

	// Just in case :shrug:
	return 0;
}

string prime_transfrom(ll n)
{
	ll cur_len = -1;
	string ans = "";

	queue<pair<ll, string>> q;
	q.push({n, ""});

	while (!q.empty()) {
		ll cur = q.front().fi;
		string mod = q.front().se;

		q.pop();
		if ((cur_len != -1) && (mod.length() > cur_len))
			continue;

		if (check_prime(cur)) {
			if (cur_len == -1) {
				cur_len = mod.length();
				ans = mod;
			}
			else ans = min(ans, mod);
		}

		if (cur_len == -1) {
			q.push({n * 2 + 1, mod + '0'});
			q.push({n + 1, mod + '1'});
		}
	}

	return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for (int i = 0; i < 9; i++) {
		cout << i << " " << PFS(i) << "\n";
	}

	cout << prime_transfrom(14) << "\n";
	cout << prime_transfrom(28) << "\n";
}
