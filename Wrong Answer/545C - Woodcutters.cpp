#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);
	ll n,ans;
	cin>>n;
	ans=min(2ll,n);
	pair<ll,ll> ar[n];
	for (int i = 0; i < n; i++) {
		ll t1,t2;
		cin>>t1>>t2;
		ar[i]={t1,t2};	
	}
	for (int i = 1; i < n-1; i++) {
		if (ar[i].first-ar[i].second>ar[i-1].first) {
			ans++;
		} else if (ar[i].first+ar[i].second<ar[i+1].first) {
			ans++;
			ar[i].first+=ar[i].second;
		}
	}
	cout<<ans<<"\n";
}
