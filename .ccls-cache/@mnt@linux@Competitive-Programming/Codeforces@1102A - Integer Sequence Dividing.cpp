#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll n;
	cin>>n;
	if (n==1) {
		cout<<1<<"\n";
		return 0;
	} else {
		ll tmp=(1+n)*(n/2)+(n%2?(n+1)/2:0);
		cout<<tmp%2<<"\n";
	}
}
