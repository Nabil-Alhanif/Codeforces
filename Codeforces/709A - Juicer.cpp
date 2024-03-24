#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll ans=0,n,b,d,waste=0;
	cin>>n>>b>>d;
	while (n--) {
		ll orange;
		cin>>orange;
		if (orange>b){
			continue;
		}
		waste+=orange;
		if (waste>d) {
			waste=0;
			ans++;
		}
	}
	cout<<ans<<"\n";
}
