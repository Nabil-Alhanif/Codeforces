#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll n, a, b, k, ans=0;
	cin >> n >> a>> b >> k;
	ll tot=a+b;
	priority_queue<ll, vector<ll>, greater<ll> > pq;
	for (int i = 0; i < n; i++) {
		ll tmp;
		cin >> tmp;
		tmp%=tot;
		if (tmp==0)tmp=tot;
		if (tmp<=a)pq.push(0);
		else {
			tmp-=a;
			ll tm=ceil((double)tmp/a);
			pq.push(tm);
		}
	}
	while (k>0&&!pq.empty()) {
		if (k-pq.top()>=0)ans++;
		k-=pq.top();
		pq.pop();
	}
	cout << ans << '\n';
}
