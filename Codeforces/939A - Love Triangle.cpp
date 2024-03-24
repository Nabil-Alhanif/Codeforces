#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll n;
	cin >> n;
	int ar[n+1];
	for (int i= 1; i <= n; i++) {
		cin >> ar[i];
	}
	bool b=0;
	for (int i = 1; i <= n; i++) {
		if (ar[ar[ar[i]]]==i) {
			b=1;
			break;
		}
	}
	if (b)cout << "YES\n";
	else cout << "NO\n";
}
