#include <bits/stdc++.h>
using namespace std;

int roll() {
	int h, rol;
	cin >> h;
	if (h%7==0) {
		rol = h/7;
	} else {
		rol = h/7+1;
	}
	return rol;
}

int main() {
	int t;
	cin >> t;
	int ar[t];
	for (int i = 0; i < t; i++) {
		ar[i] = roll();
	}
	for (int j = 0; j < t; j++) {
		cout << ar[j] << endl;
	}
}
