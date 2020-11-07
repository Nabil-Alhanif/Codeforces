#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll parent[200005], vis[200005], ans=0;
void make_set(ll v) {
    parent[v] = v;
}
ll find_set(ll v) {
	if (v == parent[v]) {
		return v;
	}
	return parent[v]=find_set(parent[v]);
}
void union_set(ll a, ll b) {
    a = find_set(a);
    b = find_set(b);
    if (a<b)parent[a]=b;
    else parent[b]=a;
}
int main() {
	ios_base::sync_with_stdio(0);
	ll n, m;
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		make_set(i);
	}
	for (ll i = 1; i <= m; i++) {
		ll a, b;
		cin >> a >> b;
		union_set(a, b);
	}
	for (ll i = 1; i <= n; i++) {
		for (ll j = i+1; j < find_set(i); j++) {
			if (find_set(i)!=find_set(j)) {
				ans++;
				union_set(i, j);
			}
		}
		i = find_set(i);
	}
	cout << ans << "\n";
}
