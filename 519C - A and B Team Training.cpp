#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,m,ans=0;
	cin>>n>>m;
	for (int i = 0; i<=n;i++) {
		ll coAns=0,a=n,b=m;
		if (b>=i*2) {
			coAns+=i;
			b-=i*2;
			a-=i;
		} else {
			ll c=b/2;
			b-=c*2;
			coAns+=c;
			a-=c;
		}
		ll d=a/2;
		if (b>=d) {
			coAns+=d;
			b-=d;
			a-=d*2;
		} else {
			coAns+=b;
		}
		ans=max(ans,coAns);
	}
	for (int i=0;i<=m;i++) {
		ll coAns=0,a=n,b=m;
		if  (a>=i*2) {
			coAns+=i;
			a-=i*2;
			b-=i;
		} else {
			ll c=a/2;
			a-=c*2;
			coAns+=c;
			b-=c;
		}
		ll d=b/2;
		if (a>=d) {
			coAns+=d;
			b-=d*2;
			a-=d;
		} else {
			coAns+=a;
		}
		ans=max(ans,coAns);
	}
	cout<<ans<<"\n";
}
