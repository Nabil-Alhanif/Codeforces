#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m, z=0;
		cin >> n >> m;
		int ar[n];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
			if (i>0)z+=ar[i];
		}
		int ans=min(ar[0]+z, m);
		cout << ans <<"\n";
	}
}
