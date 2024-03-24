#include <bits/stdc++.h>
using namespace std;

int main() {
	int ar[3];
	for (int i = 0; i < 3; i++) {
		cin >> ar[i];
	}
	sort(ar, ar+3);
	int maxs = ar[0] + ar[1];
	if (maxs > ar[2]) cout << 0 << endl;
	else {
		int mins = ar[2]+1-maxs;
		cout << mins << endl;
	}
}
