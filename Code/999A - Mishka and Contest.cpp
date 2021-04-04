#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);
	ll n,k,ans=0;
	cin>>n>>k;
	deque<ll> dq;
	while (n--) {
		ll tmp;
		cin>>tmp;
		dq.push_back(tmp);
	}
	while (!dq.empty()) {
		if (dq.front()<=k) {
			dq.pop_front();
			ans++;
		} else if (dq.back()<=k) {
			dq.pop_back();
			ans++;
		} else break;
	}
	cout<<ans<<"\n";
}
