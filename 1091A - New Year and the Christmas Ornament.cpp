#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);
	ll a,b,c,ans=0;
	cin>>a>>b>>c;
	for (int i = 1; i <= a; i++) {
		if (b>=i+1&&c>=i+2) {
			ans=i*3+3;
		}
	}
	cout<<ans<<"\n";
}
