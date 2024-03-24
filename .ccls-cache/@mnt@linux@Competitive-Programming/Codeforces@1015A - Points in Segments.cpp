#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m,num=0;
	vector<int> v;
	cin >> n >> m;
	int ar[n][2];
	int ar2[m];
	for (int i = 1; i <= m; i++) {
		ar2[i-1] = i;
	}
	for (int j = 0; j < n; j++) {
		for (int k = 0; k < 2; k++) {
			cin >> ar[j][k];
		}
	}
	for (int l = 0; l < n; l++) {
		for (int o = 0; o < m; o++) {
			if (ar2[o] >= ar[l][0] && ar2[o] <= ar[l][1]) {
				ar2[o] = 0;
			}
		}
	}
	for (int p = 0; p < m; p++) {
		if (ar2[p]!=0) {
			v.push_back(ar2[p]);
			num++;
		}
	}
	int size = v.size();
	cout << num << endl;
	for (int q = 0; q < size; q++) {
		cout << v[q] << " ";
	}
}
