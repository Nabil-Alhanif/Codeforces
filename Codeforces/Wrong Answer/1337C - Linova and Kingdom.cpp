#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> ar[200005];
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,k,ans=0;
	cin>>n>>k;
	pair<ll,pair<ll,ll> > count[n+1];
	count[0]={0,{0,0}};
	for (int i = 1;i<n;i++) {
		ll u,v;
		cin>>u>>v;
		ar[u].push_back(v);
		ar[v].push_back(u);
	}
	queue<pair<ll,pair<ll,ll> > > que;
	count[1]={0,{n-ar[1].size(),1}};
	for (auto i:ar[1]) {
		que.push({i,{1,1}});
	}
	while (!que.empty()) {
		ll pos=que.front().first;
		ll last=que.front().second.first;
		ll tmp=que.front().second.second;
		count[pos]={tmp,{n-ar[pos].size(),pos}};
		que.pop();
		for (auto i:ar[pos]) {
			if (i!=last) {
				//cout<<last<<" "<<i<<"\n";
				que.push({i,{pos,tmp+1}});
			}
		}
	}
	sort(count+1,count+1+n);
	for (int i = 0; i < k; i++) {
		//cout<<count[n-i].second.second<<" "<<count[n-i].first<<"\n";
		ans+=count[n-i].first;
		ans-=(ar[count[n-i].second.second].size()-1);
	} 
	cout<<ans<<"\n";
}
