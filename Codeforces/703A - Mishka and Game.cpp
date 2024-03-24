#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m=0, c=0;
	cin >> n;
	int ar[n][2];
	for (int i = 0; i < n; i++) {
		cin >> ar[i][0] >> ar[i][1];
	}
	for (int i = 0; i < n; i++) {
		if (ar[i][0]>ar[i][1]) m++;
		else if (ar[i][1]>ar[i][0]) c++;
		else {
			c++;
			m++;
		}
	}
	if (m > c) cout << "Mishka" << endl;
	else if (c > m) cout << "Chris" << endl;
	else cout << "Friendship is magic!^^" << endl;
}
