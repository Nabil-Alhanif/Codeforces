#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll ceil(ll a,ll n) {
	return ((a%n==0)?a/n:a/n+1);
}
int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n,g,b,m,ans=0;
		cin>>n>>g>>b;
		m=n;
		if (n<=g) {
			cout <<n<<"\n";
			continue;
		}
		n=ceil(n,2);
		if (n%g==0) {
			ans=(n/g)*(g+b)-b;
		} else {
			ans=(n/g)*(g+b)+n%g;
		}
		cout<<max(m,ans)<<"\n";
	}
}
