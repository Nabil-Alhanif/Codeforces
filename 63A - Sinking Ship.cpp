#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	string ar[n][2];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> ar[i][j];
		}
	}
	int t=0;
	vector<string> name;
	for (int i = 0; i < n; i++) {
		if (ar[i][1]=="rat") {
			name.push_back(ar[i][0]);
		}
	}
	for (int j = 0; j < n; j++) {
		if (ar[j][1]=="woman" || ar[j][1]=="child") {
			name.push_back(ar[j][0]);
		}
	}
	for (int k = 0; k < n; k++) {
		if (ar[k][1]=="man") {
			name.push_back(ar[k][0]);
		}
	}
	for (int l = 0; l < n; l++) {
		if (ar[l][1]=="captain") {
			name.push_back(ar[l][0]);
		}
	}
	for (int m = 0; m < n; m++) {
		cout << name[m] << endl;
	}
}
