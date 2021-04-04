#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int ar[3];
	for (int i = 0; i < 3; i++) {
		cin >> ar[i];
	}
	sort(ar, ar+3);
	int jarak = INT_MAX;
	for (int i = ar[0]; i <= ar[2]; i++) {
		jarak = min(jarak, abs(i-ar[0])+abs(i-ar[1])+abs(i-ar[2]));
	}
	cout << jarak << "\n";
}
