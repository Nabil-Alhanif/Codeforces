#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int t;
	cin>>t;
	while (t--) {
		ll a,b;
		cin>>a>>b;
		ll c=__gcd(a,b);
		b/=c;
		ll ans=b,tmp=b;
		for (int i = 2; i<=sqrt(tmp); i++) {
			bool iya=0;
			while(b%i==0) {
				b/=i;
				iya=1;
			}
			if(iya)ans=ans/i*(i-1);
		}
		if(b!=1) {
			ans=ans/b*(b-1);
		}
		cout<<ans<<"\n";
	}
}
