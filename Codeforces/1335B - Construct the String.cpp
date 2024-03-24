#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while (t--) {
		ll n,a,b;
		cin>>n>>a>>b;
		char s[a];
		int i=0;
		for (char c='a';i<b;i++,c++) {
			//cout<<i<<" "<<c<<"\n";
			s[i]=c;
		}
		//cout<<i<<"\n";
		for (i;i<a;i++) {
			s[i]='a';
		}
		for (i=0; i<a; i++) {
			cout<<s[i];
		}
		for (i;i<n;i++) {
			cout<<s[i%a];
		}cout<<"\n";
	}
}
