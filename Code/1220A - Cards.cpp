#include <bits/stdc++.h>

using namespace std;

int main() {
	int t, n = 0, z = 0;
	cin >> t;
	string ar;
	cin >> ar;
	for (int j = 0; j < t; j++) {
		if (ar[j] == 'z') z += 1;
		if (ar[j] == 'n') n += 1;
	}
	for (int k = 0; k < n; k++) {
		cout << 1;
		cout << " ";
	}
	for (int i = 0; i < z; i++) {
		cout << 0 ;
		cout << " ";
	}
}
