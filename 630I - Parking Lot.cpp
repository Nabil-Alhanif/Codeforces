#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll pow(ll a, ll b) {
	ll ret=1;
	while (b>0) {
		ret*=a;
		b--;
	}
	return ret;
}
int main() {
	ll n;
	cin >> n;
	ll p=n*2-n-1;
	ll t = n*2-2;
	ll ans=1;
	ans*=pow(4, t-n);
	ans*=p;
	for (int i = 0; i <= t-n; i++) {
		ll tmp = pow(4, i-1);
		ll tmp2 = pow(4, t-n-i-1);
		if (t-n-i>0) {
			tmp*=3;
			if (t-n-i>1) {
				tmp*=pow(4, t-n-i-1);
			}
		}
		if (i>0) {
			tmp2*=3;
			if (i>1) {
				tmp2*=pow(4, i-1);
			}
		}
		ll tmp3=0;
		if (t-n-i>0&&i>0) {
			tmp3 = 1;
			if (t-n-i>1) {
				tmp3*=pow(4, t-n-i-1);
			}
			if (i>1) {
				tmp3*=pow(4, i-1);
			}
		}
		ans-=tmp;
		ans-=tmp2;
		ans-=tmp3;
	}
	cout << ans*4 <<'\n';
}
