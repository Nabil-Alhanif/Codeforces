#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	while (t--) {
		ll a, b;
		cin>>a>>b;
		if(a%b==0)cout<<"0\n";
		else cout<<b-(a%b)<<"\n";
	}
}
