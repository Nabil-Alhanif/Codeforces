#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//sadasdasd
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while (t--) {
		ll n,mins=LLONG_MAX,tot=0,ans=LLONG_MAX;
		cin>>n;
		pair<ll,ll> ar[n];
		ll con[n];
		for (int i = 0; i < n; i++) {
			ll a,b;
			cin>>a>>b;
			mins=min(mins,a);
			if (i!=0) {
				con[i]=max(0ll,a-ar[i-1].second);
				tot+=con[i];
			}
			if (i==n-1){
				con[0]=max(0ll,ar[0].first-b);
				tot+=con[0];
			}
			ar[i]={a,b};
			//cout<<tot<<"\n";
		}
		//cout<<tot<<"\n";
		for (int i = 0; i < n; i++) {
			//cout<<ar[i].first<<" "<<ar[i].second<<" "<<con[i]<<"\n";
			ll tmp=tot+ar[i].first-con[i];
			ans=min(ans,tmp);
		}
		cout<<ans<<"\n";
	}
}
