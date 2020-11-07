#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	unsigned long long ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	sort(ar, ar+n);
	unsigned long long n2 = n/2;
	unsigned long long x=0, y=0;
	for (int i = 0; i < n2; i++) {
		y+=ar[i];
	}
	for (int i = n2; i < n; i++) {
		x+=ar[i];
	}
	unsigned long long total = y*y+x*x;
	cout << total << "\n";
}
