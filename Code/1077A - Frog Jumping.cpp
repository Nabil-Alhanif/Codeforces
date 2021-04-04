#include <bits/stdc++.h>
using namespace std;

long long pos() {
	long long a, b, k,total = 0;;
	cin >> a >> b >> k;
	long long min = a-b;
	int k2 = k/2;
	total += k2*min;
	if (k%2 == 1) total += a;
	return total;
}

int main() {
	int t;
	cin >> t;
	long long ar[t];
	for (int i = 0; i < t; i++) {
		ar[i] = pos();
	}
	for (int j = 0; j < t; j++) {
		cout << ar[j] << endl;
	}
}
