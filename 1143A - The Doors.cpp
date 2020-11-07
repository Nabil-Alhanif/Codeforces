#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, left, right;
	cin >> n;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	for (int j = 0; j < n; j++) {
		if (ar[j] == 0) left = j;
		if (ar[j] == 1) right = j;
	}
	if (left < right) cout << left+1 << endl;
	if (right < left) cout << right+1 << endl;
}
