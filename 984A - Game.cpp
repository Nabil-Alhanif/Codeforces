#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int n2 = n/2;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	sort(ar, ar+n);
	if (n%2==1) {
		cout << ar[n2] << endl;
	} else {
		cout << min(ar[n2], ar[n2-1]) << endl;
	}
}
