#include <bits/stdc++.h>
using namespace std;

int main() {
	int k, grow=0, time=0;
	cin >> k;
	int ar[12];
	for (int i = 0; i < 12; i++) {
		cin >> ar[i];
	}
	sort (ar, ar+12);
	if (k==0) cout << 0 << endl;
	else {
		for (int i = 11; i >=0; i--) {
			grow+=ar[i];
			time++;
			if (grow>=k) {
				cout << time << endl;
				break;
			}
		}
		if (grow < k) cout << -1 << endl;
	}
}
