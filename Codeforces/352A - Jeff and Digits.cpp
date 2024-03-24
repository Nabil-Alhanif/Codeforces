#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int ar[n];
	long long c5 = 0, c0 = 0;
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		if (ar[i]==5) c5++;
		else c0++;
	}
	int temp = c5/9;
	if (temp == 0) {
		if (c0!=0) cout << 0 << "\n";
		else cout << -1 << "\n";
	} else {
		if (c0 > 0) {
			temp*=9;
			for (int i = 0; i < temp; i++) {
				cout << 5;
			}
			for (int i = 0; i < c0; i++) {
				cout << 0;
			} cout << "\n";
		} else cout << "-1\n";
	}
}
