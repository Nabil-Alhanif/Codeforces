#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> v;
	int n, stairs=0;
	cin >> n;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	for (int j = 1; j < n; j++) {
		if (ar[j]==1) {
			stairs += 1;
			v.push_back(ar[j-1]);
		}
	}
	v.push_back(ar[n-1]);
	stairs+=1;
	cout << stairs << endl;
	for (int k = 0; k < v.size(); k++) {
		cout << v[k] << " ";
	}
}
