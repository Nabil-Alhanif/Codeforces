#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,a,b;
	ll t;
	cin>>t;
	while(t--) {
		cin>>n>>a>>b;
		if (a*2<=b) {
			cout<<a*n<<"\n";
		} else {
			cout<<b*(n/2)+(n%2?a:0)<<"\n";
		}
	}
}
