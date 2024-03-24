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


ll calc(ll a, ll b, char c)
{
	if ((c == '/') && (a % b != 0))
		return 1e9;

	if (c == '/')
		return a / b;
	if (c == '+')
		return a + b;
	if (c == '-')
		return a - b;
	if (c == '*')
		return a * b;
	return 1e9;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	char opr[4] = {'+', '-', '*', '/'};

	vector<ll> arr(4);
	for (int i = 0; i < 4; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	do {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					ll ret = calc(arr[0], arr[1], opr[i]);
					ret = calc(ret, arr[2], opr[j]);
					ret = calc(ret, arr[3], opr[k]);

					if (ret == 24) {
						cout << "( ( (" << arr[0] << " " << opr[i] << " " << arr[1] << ") " << opr[j] << " " << arr[2] << ") " << opr[k] << " " << arr[3] << ")\n";
						return 0;
					}
				}
			}
		}
	}
	while (next_permutation(arr.begin(), arr.end()));
}
