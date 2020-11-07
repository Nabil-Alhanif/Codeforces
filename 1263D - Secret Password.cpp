#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll parent[1000000], ranking[1000000], vis[1000000];
map<char, ll> m;
void make_set(ll v) {
	parent[v]=v;
	ranking[v]=0;
}
ll find_set(ll v) {
	if (v == parent[v]) {
		return v;
	}
	return parent[v]=find_set(parent[v]);
}
void union_set(ll x, ll y) {
	x = find_set(x);
	y = find_set(y);
	if (ranking[x]<ranking[y])parent[x]=y;
	else parent[y]=x;
	if (ranking[x]==ranking[y])ranking[x]++;
}
int main() {
	ios_base::sync_with_stdio(0);
	ll n;
	cin >> n;
	for (ll z = 1; z<=n; z++) {
		make_set(z);
	}
	for (ll z = 1; z <= n; z++) {
		string s;
		cin >> s;
		ll size = s.length();
		for (int i = 0; i < size; i++) {
			if (m[s[i]]==0) {
				m[s[i]]=z;
			} else  {
				union_set(z, m[s[i]]);
			}
		}
	}
	ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		ll tmp = find_set(i);
		if(vis[tmp] == 0){
			ans++;
			vis[tmp]=1;
		}
	}
	cout << ans << "\n";
}
