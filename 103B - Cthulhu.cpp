#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool bo[101];
int main() {
	ll n, m;
	cin >> n >> m;
	vector<ll> v[n+1];
	for (int i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	queue<ll> q;
	q.push(1);
	bo[1]=true;
	bool k=true;
	while (!q.empty()) {
		ll x=q.front();
		q.pop();
		for (auto i:v[x]) {
			if (!bo[i]) {
				bo[i]=true;
				q.push(i);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!bo[i]) {
			k=false;
			break;
		}
	}
	if (k&&n==m)cout << "FHTAGN!\n";
	else cout << "NO\n";
}
