#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, most, give = 0;
	cin >> n;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	most = ar[0];
	for (int j = 0; j < n; j++) {
		if (ar[j] > most) most = ar[j];
	}
	for (int k = 0; k < n; k++) {
		give += most-ar[k];
	}
	cout << give << endl;
}
