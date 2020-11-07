#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int ar[n];
	for (int i= 0; i < n; i++) {
		cin >> ar[i];
	}
	sort(ar, ar+n);
	int i = 0;
	int j = n-1;
	int back = n/2;
	int k = 1;
	while (k<=n) {
		if (k%2==1) {
			cout << ar[i] << " ";
			i++;
		} else {
			cout << ar[j] << " ";
			j--;
		}
		k++;
	}
	cout << "\n";
}
