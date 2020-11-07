#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, t;
	cin >> n >> t;
	int ar[n];
	for (int i = 0; i < n-1; i++) {
		cin >> ar[i];
	}
	for (int i = 0; i < n; i) {
		if (i==t-1) {
			cout << "YES\n";
			break;
		}
		else if (i>t-1) {
			cout << "NO\n";
			break;
		}
		i+=ar[i];
	}
}
