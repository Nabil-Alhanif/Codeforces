#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll r,x,y,x1,y1;
	cin>>r>>x>>y>>x1>>y1;
	r*=2;
	ll dx=max(x,x1)-min(x,x1);
	ll dy=max(y,y1)-min(y,y1);
	if (dx&&dy) {
		ll hyp=sqrt(dx*dx+dy*dy);
		if (hyp*hyp!=dx*dx+dy*dy)hyp++;
		ll ans=hyp/r+(hyp%r?1:0);
		cout<<ans<<"\n";
	} else if (dx&&!(dy)) {
		ll ans=dx/r+(dx%r?1:0);
		cout<<ans<<"\n";
	} else if (dy&&!(dx)) {
		//cout<<"sdaa\n";
		//cout<<max(y,y1)<<" "<<min(y,y1)<<"\n";
		ll ans=dy/r+(dy%r?1:0);
		cout<<ans<<"\n";
	} else cout<<"0\n";
}
