#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool bo[100005];
vector<int> v[100001];
queue<ll> q;
int main() {
	ios_base::sync_with_stdio(0);
	ll n, m, ans=0, minGold=0;
	cin >> n >> m;
	ll gold[n+1];
	for(int i= 1; i <=n;i++) {
		cin >> gold[i];
	}
	for (int i = 1; i <= m; i++) {
		ll a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (!bo[i]) {
			bo[i]=true;
			q.push(i);
			minGold=gold[i];
			while (!q.empty()) {
				ll x= q.front();
				q.pop();
				minGold=min(minGold, gold[x]);
				for (auto j:v[x]) {
					if (!bo[j]) {
						q.push(j);
						bo[j]=true;
					}
				}
			}ans+=minGold;
		}
	}
	cout << ans << "\n";
}
