#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
	ll n, m;
	scanf("%lld %lld", &n, &m);
	ll l = 0, r=n;
	ll tmp=0, ans=0;
	while (l<=r) {
		ll mid = (l+r)/2;
		tmp = n-mid;
		if ((mid*(mid+1)/2)-tmp==m) {
			ans = tmp;
			break;
		} else if ((mid*(mid+1)/2)-tmp<m) {
			l = mid+1;
		} else if ((mid*(mid+1)/2)-tmp>m) {
			r = mid-1;
		}
	}
	printf("%lld\n", tmp);
}
