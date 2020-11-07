#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, count=0;
		cin>> n;
		int ar[n];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
			if (ar[i]%2==1) {
				count++;
			}
		}
		int genap = n-count;
		if (count%2==1) cout << "YES\n";
		else if (count==0)cout << "NO\n";
		else {
			if (genap>0)cout << "YES\n";
			else cout << "NO\n";
		}
	}
}
