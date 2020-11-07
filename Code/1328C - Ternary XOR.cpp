#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);
	ll t;
	cin>>t;
	while(t--) {
		ll n;
		cin>>n;
		string c;
		cin>>c;
		ll a[n],b[n],cA=0,cB=0;
		bool dah=0;
		for (int i = 0; i < n; i++) {
			if(!dah) {
				if((c[i]-'0')%2==0) {
					a[i]=(c[i]-'0')/2;
					b[i]=(c[i]-'0')/2;
				} else {
					dah=true;
					a[i]=(c[i]-'0');
					b[i]=0;
				}
			} else {
				a[i]=0;
				b[i]=(c[i]-'0');
			}
		}
		for (int i = 0; i < n; i++) {
			cout<<a[i];
		}cout<<"\n";
		for(int i = 0; i < n; i++) {
			cout<<b[i];
		}cout<<"\n";
	}
}
