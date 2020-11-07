#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll q;
	cin>>q;
	while (q--) {
		ll a,b,c,ans=LLONG_MAX;
		cin>>a>>b>>c;
		for (int i = -1; i < 2; i++) {
			for (int j = -1; j< 2; j++) {
				for (int k = -1; k < 2; k++) {
					ans=min(ans,abs((a+i)-(b+j))+abs((a+i)-(c+k))+abs((b+j)-(c+k)));
				}
			}
		}
		cout<<ans<<"\n";
	}
}
