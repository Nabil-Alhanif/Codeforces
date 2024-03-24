#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, most;
	vector<int> v;
	cin >> n;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	sort(ar, ar+n);
	int temp2 = 1;
	for (int j = 0; j < n; j++) {
		int temp = ar[j];
		if(ar[j+1]==ar[j]) {
			temp2 += 1;
		}
		if (ar[j+1] != ar[j]) {
			v.push_back(temp2);
			temp2 = 1;
		}
	}
	most = v[0];
	for (int k = 0; k < v.size(); k++) {
		if (v[k] >= most) {
			most = v[k];
		}
	}
	cout << most << endl;
}
