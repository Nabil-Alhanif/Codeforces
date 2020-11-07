#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, sum, t;
	cin >> n;
	if (n%2==1) {
		t = floor(n/2);
		cout << t << endl;
		for (int i = 1; i < t; i++) {
			cout << 2 << " ";
		} cout << 3 << endl;
	} else {
		sum = n/2;
		cout << sum << endl;
		for (int i = 1; i < sum; i++) {
			cout << 2 << " ";
		} cout << 2 << endl;
	}
}
