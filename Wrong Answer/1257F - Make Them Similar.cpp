#include <bits/stdc++.h>
using namespace std;

int bin(int n) {
	int t=0;
	while (n>0) {
		t+=n%2;
		n/=2;
	}
	return t;
}

int main() {
	int n, x=-1;
	cin >> n;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	for (int i = 1; i <= 2147483647; i++) {
		bool yes=true;
		for (int j = 0; j < n-1; j++) {
			if (bin(ar[j]^i)!=bin(ar[j+1]^i)) {
				yes = false;
				break;
			}
		}
		if (yes) {
			x=i;
			break;
		}
	}
	cout << x << "\n";
}
