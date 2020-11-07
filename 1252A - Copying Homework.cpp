#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int ar[n], ar2[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	int ar3[n];
	for (int i = 0; i < n; i++) {
		ar3[i] = n-ar[i]+1;
		cout << ar3[i] << " ";
	} cout << endl;
}
