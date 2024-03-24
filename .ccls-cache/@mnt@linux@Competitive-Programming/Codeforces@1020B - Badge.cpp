#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll n;
	cin >> n;
	ll ar[n+1];
	for (int i = 1; i <= n; i++) {
		cin >> ar[i];
	}
	for (int i = 1; i <= n; i++) {
		bool b[n+1];
		memset(b, 0, sizeof(b));
		b[i]=true;
		queue<int> q;
		q.push(ar[i]);
		while (!q.empty()) {
			ll a=q.front();
			if (b[a]) {
				cout << a;
				break;
			}
			b[a]=true;
			q.pop();
			q.push(ar[a]);
		}
		if (i!=n)cout <<" ";
	} cout <<"\n";
}
