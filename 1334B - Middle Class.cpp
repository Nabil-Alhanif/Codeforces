#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//assadsad
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while (t--) {
		ll n,x;
		cin>>n>>x;
		ll ar[n];
		for (int i = 0; i < n; i++) {
			cin>>ar[i];
		}
		sort(ar,ar+n,greater<int>());
		ll coun=0,ans=0;
		for (int i = 0; i < n; i++) {
			coun+=ar[i];
			if (coun/(i+1)>=x) {
				ans=i+1;
			} else break;
		}
		cout<<ans<<"\n";
	}
}
