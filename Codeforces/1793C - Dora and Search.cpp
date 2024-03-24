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


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t;
	cin >> t;

	while (t--) {
		ll n;
		cin >> n;
		vector<ll> arr(n);

		priority_queue<ll, vector<ll>, greater<ll>> mins;
		priority_queue<ll> maks;

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			mins.push(arr[i]);
			maks.push(arr[i]);
		}

		int l, r;
		for (l = 0, r = n - 1; l < r; ) {
			//cout << l << " " << r << "\n";
			ll cmin = mins.top();
			ll cmax = maks.top();

			bool ubah = 0;

			bool lmin = (arr[l] == cmin);
			bool lmax = (arr[l] == cmax);
			bool rmin = (arr[r] == cmin);
			bool rmax = (arr[r] == cmax);

			if (lmin) {
				l++;
				mins.pop();
			}
			else if (lmax) {
				l++;
				maks.pop();
			}
			else if (rmin) {
				r--;
				mins.pop();
			}
			else if (rmax) {
				r--;
				maks.pop();
			}
			else break;
		}

		if (l < r)
			cout << l + 1 << " " << r + 1 << "\n";
		else cout << "-1\n";
	}
}
