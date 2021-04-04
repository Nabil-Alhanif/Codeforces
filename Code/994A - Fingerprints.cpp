#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int ar[n];
	int ar2[m];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	for (int j = 0; j < m; j++) {
		cin >> ar2[j];
	}
	vector<int> v;
	int k = 0;
	while (k < n) {
		for (int i = 0; i < m; i++) {
			if (ar[k] == ar2[i]) {
				v.push_back(ar[k]);
			}
		}
		k++;
	}
	for (int p = 0; p < v.size(); p++) {
		cout << v[p] << " ";
	}
}
