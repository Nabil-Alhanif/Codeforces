#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	int ar[t], one=0, zero=0;
	for (int i = 0; i < t; i++) {
		cin >> ar[i];
		ar[i]%=2;
		if (ar[i]==0)zero++;
		else one++;
	}
	if (one==1) {
		for (int i = 0; i < t; i++) {
			if (ar[i]==1) {
				cout << i+1 << "\n";
				break;
			}
		}
	} else {
		for (int i = 0; i < t; i++) {
			if (ar[i]==0) {
				cout << i+1 << "\n";
				break;
			}
		}
	}
}
