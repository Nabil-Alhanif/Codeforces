#include <bits/stdc++.h>

using namespace std;

int main() {
	int t, dif = 1;
	cin >> t;
	int ar[t] = {};
	for (int i = 0; i < t; i++) {
		cin >> ar[i];
	}
	for (int j = 0; j < t-1; j++) {
		if (ar[j] == ar[j+1]) continue;
		else dif += 1;
	}
	cout << dif << endl;
}
