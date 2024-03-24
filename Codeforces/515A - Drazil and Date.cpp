#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);
	ll a,b,s;
	cin>>a>>b>>s;
	a=abs(a)+abs(b);
	if(s<a) {
		cout<<"No\n";
		return 0;
	}
	a-=s;
	if (a%2) {
		cout<<"No\n";
		return 0;
	}
	cout<<"Yes\n";
}
