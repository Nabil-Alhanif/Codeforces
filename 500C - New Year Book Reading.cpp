#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool b[501];
int main() {
	ll n, m, ans=0;
	cin >> n >> m;
	ll weight[n], book[m];
	stack<ll> s, s1;
	for (int i = 0; i < n; i++) {
		cin >> weight[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> book[i];
		if (!b[book[i]]) {
			s1.push(book[i]);
			b[book[i]]=true;
		}
	}
	while (!s1.empty()) {
		s.push(s1.top());
		s1.pop();
	}
	for (int i = 0; i < m; i++) {
		while (s.top()!=book[i]) {
			s1.push(s.top());
			ans+=weight[s.top()-1];
			s.pop();
		}
		ll tmp=s.top();
		s.pop();
		while (!s1.empty()) {
			s.push(s1.top());
			s1.pop();
		}
		s.push(tmp);
	}
	cout << ans << "\n";
}
