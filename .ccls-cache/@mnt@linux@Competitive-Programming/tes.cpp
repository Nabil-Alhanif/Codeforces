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

template <typename T>
using pt = complex<T>;
#define X real()
#define Y imag()

const ll MOD = 1e9 + 7, INF = LLONG_MAX;
const double PI = acos(-1);


/* Question specific function and variable */

/* Note to self
 *
 * - Don't use a data structure when you don't need to
 * */


int ayam(int a, int b)
{
	int ret = 0;
	for (int i = a; i <= b; i++)
		ret *= i;
	return ret;
}

void bebek(int a, int b)
{
	int ret = 0;
	for (int i = ayam(a, b); i <= a * b; i++) {
		if (i % a == 0)
			ret += b;
	}
	cout << ret << "\n";
}

void kambing(int a)
{
	int ret = 1;
	for (int i = 0; i < 8; i++) {
		if (a & (1 << i))
			ret *= (1 << i);
	}
	cout << ret << "\n";
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n;
	cin >> n;

	vector<ll> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	ll ans = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++)
			ans += arr[i] * arr[j];
	}
	cout  << ans << "\n";
}
