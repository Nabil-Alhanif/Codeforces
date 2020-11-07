#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//jkbjkb
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while (t--) {
		ll n,player=0,clears=0;
		cin>>n;
		bool bisa=1;
		while (n--){
			ll p,c;
			cin>>p>>c;
			ll c1=p-player,c2=c-clears;
			if (c1<0||c2<0) {
				bisa=0;
			}
			if(c2>c1) {
				bisa=0;
			}
			player=p;
			clears=c;
		}
		if(bisa)cout<<"YES\n";
		else cout<<"NO\n";
	}
}
