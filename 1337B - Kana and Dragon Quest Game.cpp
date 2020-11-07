#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while (t--) {
		ll a,n,m;
		cin>>a>>n>>m;
		while (n--) {
			if (a<=10)break;
			if (a<22) {
				a=20;
				break;
			}
			if (a%2==1)a-=1;
			a/=2;
			a+=10;
		}
		if (m*10>=a)a=0;
		if (a<=0)cout<<"YES\n";
		else cout<<"NO\n";
	}
}
