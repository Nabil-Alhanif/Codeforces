#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	ll m=max(3*a/10,a-(a/250*c));
	ll v=max(3*b/10,b-(b/250*d));
	if (m==v) {
		cout<<"Tie\n";
		return 0;
	}
	cout<<(m>v?"Misha\n":"Vasya\n");
}
