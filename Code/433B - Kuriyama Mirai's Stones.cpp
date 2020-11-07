#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin>>n;
	ll a[n+1],b[n+1];
	a[0]=0;b[0]=0;
	for (int i = 1; i <= n; i++) {
		cin>>a[i];
		b[i]=a[i];
		a[i]+=a[i-1];
	}
	sort(b,b+n+1);
	for (int i = 1; i <= n; i++) {
		b[i]+=b[i-1];
	}
	ll t;
	cin>>t;
	while (t--) {
		ll ty, l, r;
		cin>>ty>>l>>r;
		if (ty==1) {
			cout<<a[r]-a[l-1]<<"\n";
		} else cout<<b[r]-b[l-1]<<"\n";
	}
}
