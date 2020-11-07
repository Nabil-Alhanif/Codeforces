#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while (t--) {
		ll n;
		cin>>n;
		ll ar[n];
		for (int i = 0; i < n; i++) {
			cin>>ar[i];
		}
		sort(ar,ar+n);
		vector<ll> ans;
		int i=0, l=n-1;
		while (i<=l) {
			if (i!=l) {
				ans.push_back(ar[i]);
				ans.push_back(ar[l]);
			} else {
				ans.push_back(ar[i]);
			}
			i++;
			l--;
		}
		for (int i = n-1; i>=0;i--) {
			cout<<ans[i]<<" ";
		}cout<<"\n";
	}
}
