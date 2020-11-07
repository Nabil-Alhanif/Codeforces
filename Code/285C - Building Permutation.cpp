#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	unsigned long long move = 0;
	cin >> n;
	int ar[n], ar2[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		ar2[i]=i+1;
	}
	sort(ar, ar+n);
	for (int i = 0; i < n; i++) {
		move+=max(ar2[i], ar[i])-min(ar2[i], ar[i]);
	}
	cout << move << "\n";
}
