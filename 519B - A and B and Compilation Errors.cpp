#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int ar[n], ar2[n-1], ar3[n-2];
	map<int, int> m, m2, be;
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		be[ar[i]]++;
	}
	for (int i = 0; i < n-1; i++) {
		cin >> ar2[i];
		m[ar2[i]]++;
	}
	for (int i = 0; i < n-2; i++) {
		cin >> ar3[i];
		m2[ar3[i]]++;
	}
	for (int i = 0; i < n; i++) {
		if (be[ar[i]]!=m[ar[i]]) {
			cout << ar[i] << "\n";
			break;
		}
	}
	for (int i = 0; i < n-1; i++) {
		if (m[ar2[i]]!=m2[ar2[i]]) {
			cout << ar2[i] << "\n";
			break;
		}
	}
}
