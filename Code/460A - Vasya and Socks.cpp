#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int i = 0;
	for (n; n > 0; n--, i++) {
		if (i%m==0)n++;
	}
	cout << i-1 << "\n";
}
