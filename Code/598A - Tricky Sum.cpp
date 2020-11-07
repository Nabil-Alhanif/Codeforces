#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll t;
	cin>>t;
	while(t--) {
		ll n;
		cin>>n;
		ll sum=(1+n)*(n/2)+(n%2?n/2+1:0);
		for (int i = 1;i<=n;i*=2) {
			sum-=i*2;
		}
		cout<<sum<<"\n";
	}
}
