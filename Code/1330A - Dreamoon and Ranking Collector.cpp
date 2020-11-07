#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while (t--) {
		ll n,x;
		cin>>n>>x;
		vector<ll> v;
		v.push_back(0);
		for (int i = 0; i < n; i++) {
			ll tmp;
			cin>>tmp;
			v.push_back(tmp);
		}
		sort(v.begin(),v.end());
		v.resize(distance(v.begin(),unique(v.begin(),v.end())));
		ll size=v.size(),pos=0;
		for (int i = 1; i < size; i++) {
			ll tmp=v[i]-v[i-1]-1;
			if(x>=tmp) {
				pos=i;
				x-=tmp;
			} else {
				break;
			}
		}
		cout<<v[pos]+x<<"\n";
	}
}
