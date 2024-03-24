#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll ans=LLONG_MIN;
	ll n,k;
	cin>>n>>k;
	while (n--) {
		ll a,b;
		cin>>a>>b;
		ll tmp=a;
		if (b>k) {
			tmp=a-(b-k);
		}
		ans=max(ans,tmp);
	}
	cout<<ans<<"\n";
}
