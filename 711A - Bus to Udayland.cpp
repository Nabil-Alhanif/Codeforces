#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	char ar[n][5];
	for (int k = 0; k < n; k++) {
		for (int j = 0; j < 5; j++) {
			cin >> ar[k][j];
		}
	}
	bool can = false;
	for (int i = 0; i < n; i++) {
		if (ar[i][0]=='O'&&ar[i][1]=='O') {
			ar[i][0]='+';
			ar[i][1]='+';
			can = true;
			break;
		} else if(ar[i][3]=='O'&&ar[i][4]=='O') {
			ar[i][3]='+';
			ar[i][4]='+';
			can = true;
			break;
		}
	}
	if (can) {
		cout << "YES" << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 5; j++) {
				cout << ar[i][j];
			} cout << endl;
		}
	} else cout << "NO" << endl;
}
