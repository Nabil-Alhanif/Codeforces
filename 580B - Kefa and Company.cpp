#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pp;
int main() {
	ll n, d, ans=0;
	cin >> n >> d;
	pair<ll, ll> ar[n];
	for (int i = 0; i < n; i++) {
		ll m, s;
		cin >> m >> s;
		ar[i]={m,s};
	}
	sort(ar, ar+n);
	for (int i = 1; i<n; i++) {
		ar[i]={ar[i].first, ar[i].second+ar[i-1].second};
	}
	for (int i = n-1; i >= 0; i--) {
		ll tmp = lower_bound(ar, ar+n, pp(ar[i].first-d+1, numeric_limits<ll>::min()))-ar-1;
		if (tmp<0)ans=max(ans, ar[i].second);
		else ans=max(ans, ar[i].second-ar[tmp].second);
		//cout<<"tmp: "<<tmp<<" ar[i], ar[tmp]: "<<ar[i].second<<" "<<ar[tmp].second<<"\n";
	}
	cout << ans << "\n";
}
