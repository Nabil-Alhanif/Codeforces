#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while (t--) {
		ll n,coun=0,last=0,ans=0;
		cin>>n;
		ll ar[n];
		vector<pair<ll,ll> >v;
		map<ll,ll> m3;
		for (int i=0;i<n;i++){
			cin>>ar[i];
			if (i==0) {
				coun=0;
				last=ar[0];
			}
			if (ar[i]!=last) {
				last=ar[i];
				v.push_back({ar[i-1],coun});
				coun=0;
			}
			m3[ar[i]]++;
			coun++;
		}
		v.push_back({ar[n-1],coun});
		n=v.size();
		map<ll,ll> m;
		for (int i = 0; i < n; i++) {
			m[v[i].first]+=v[i].second;
			ll localMax=0;
			ans=max(ans,m[v[i].first]);
			map<ll,ll> m2;
			for (int j = i+1; j<n; j++) {
				ll tmp;
				m2[v[j].first]+=v[j].second;
				if (v[j].first!=v[i].first)localMax=max(localMax,m2[v[j].first]);
				else localMax=max(localMax,m2[v[j].first]-v[j].second);
				if (v[i].first==v[j].first) {
					tmp=m3[v[i].first];
					tmp-=m[v[i].first];
					tmp=max(tmp-m2[v[j].first]+v[j].second,v[j].second);
					//cout<<tmp<<"\n";
					tmp=min(tmp,m[v[i].first]);
					ans=max(ans,tmp+tmp+localMax);
				}
				//cout<<tmp<<" "<<localMax<<"\n";
			}
		}
		cout<<ans<<"\n";
	}
}
