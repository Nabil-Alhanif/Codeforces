#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	double total = 0;
	double ans;
	cin >> t;
	int ar[t] = {};
	for (int i = 0; i < t; i++) {
		cin >> ar[i];
	}
	for (int j = 0; j < t; j++) {
		total += ar[j];
	}
	ans = total/t;
	cout.precision(14);
	cout << ans << fixed << endl;
}
