#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);
	ll t;
	cin>>t;
	while(t--) {
		ll n, k;
		cin>>n>>k;
		n-=2;
		ll i=0, j=-1;
		while(k>i) {
			k-=i;
			i++;
			j++;
		}
		k--;
		//cout<<k<<" "<<i<<" "<<j<<"\n";
		ll fA=n-i+1;
		n-=fA;
		n-=k;
		if(fA)cout<<string(fA,'a');
		cout<<'b';
		if(n)cout<<string(n,'a');
		cout<<'b'<<string(k,'a');
		cout<<"\n";
	}
}
