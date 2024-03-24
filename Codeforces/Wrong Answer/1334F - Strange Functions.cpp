#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin>>n;
	ll a[n],p[n];
	for (int i = 0; i < n; i++) {
		cin>>a[i];
	}
	for (int i = 0; i < n; i++) {
		cin>>p[i];
	}
	ll m;
	cin>>m;
	ll b[m+1];
	for (int i = 0; i < m; i++) {
		cin>>b[i];
	}
	b[m]=LLONG_MIN;
	ll ans=0,pos=0;
	bool found=0;
	for (int i = 0; i < n; i++) {
		if (b[pos]==a[i]) {
			pos++;
			if (pos==m)found=1;
			pos=min(pos,m);
			continue;
		}
		if (pos==0) {
			ans+=p[i];
		} else {
			if (a[i]>b[pos-1]||p[i]<0)ans+=p[i];
		}
	}
	if(found) {
		cout<<"YES\n";
		cout<<ans<<"\n";
	}
	else cout<<"NO\n";
}
