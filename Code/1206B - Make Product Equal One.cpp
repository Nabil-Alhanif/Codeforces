#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll n,m=0,z=0,ans=0;
	cin>>n;
	for (ll i = 0; i < n; i++) {
		ll tmp;
		cin>>tmp;
		ans+=abs(abs(tmp)-1);
		if (tmp<0)m++;
		if(tmp==0)z++;
	}
	if(m%2&&!(z))ans+=2;
	cout<<ans<<"\n";
}
