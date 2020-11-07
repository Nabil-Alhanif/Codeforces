#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, count = 0;
	cin >> n;
	for (int i = 1; i < n; i++) {
		for (int j = i; j < n; j++) {
			unsigned long long c = i*i+j*j;
			unsigned long long d = sqrt(c);
			if (d*d==i*i+j*j&&d<=n) count++;
		}
	}
	cout << count << "\n";
}
