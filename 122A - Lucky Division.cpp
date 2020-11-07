#include <bits/stdc++.h>
using namespace std;

int lucky[14] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777};
int main() {
	int n;
	cin >> n;
	bool can = false;
	for (int i = 0; i < 14; i++) {
		if(n % lucky[i] != 0) continue;
		if (n%lucky[i] == 0) can = true;
	}
	if (can) cout << "YES" << endl;
	else cout << "NO" << endl;
}
