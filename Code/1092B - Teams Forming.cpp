#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, prob = 0; 
	cin >> n;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	sort(ar, ar+n);
	for (int j = 0; j < n-1; j+=2) {
		int temp;
		temp = ar[j+1]-ar[j];
		prob += temp;
	}
	cout << prob << endl;
}
