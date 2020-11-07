#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);
	ll n,ans=0;
	cin>>n;
	ll ar[n];
	for (int i = 0; i < n; i++){
		cin>>ar[i];
	}
	sort(ar,ar+n);
	for (int i = 1; i < n; i++) {
		ans+=ar[i]-ar[i-1]-1;
	}
	cout<<ans<<"\n";
}
