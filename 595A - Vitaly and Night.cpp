#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, on=0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int a, b;
			cin >> a >> b;
			if (a==1 || b==1) {
				on++;
			}
		}
	}
	cout << on << endl;
}
