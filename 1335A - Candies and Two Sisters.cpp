#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while (t--) {
		ll n;
		cin>>n;
		if (n==1||n==2) {
			cout<<"0\n";
			continue;
		}
		if (n%2) {
			cout<<n/2<<"\n";
		}else {
			n/=2;
			cout<<n-1<<"\n";
		}
	}
}
