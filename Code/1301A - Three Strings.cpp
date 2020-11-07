#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		string a, b, c;
		cin >> a>> b >> c;
		int size=a.size();
		bool can=true;
		for (int i = 0; i < size; i++) {
			if (c[i]!=a[i]&&c[i]!=b[i]) {
				can=false;
				break;
			}
		}
		if (can) cout<<"YES\n";
		else cout<<"NO\n";
	}
}
