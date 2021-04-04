#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int ar[n];
		for (int i= 0; i < n; i++) {
			cin >> ar[i];
		}
		int m;
		cin >> m;
		pair<int, int> ar2[m];
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			ar2[i] = make_pair(x, y);
		}
		int j = 0, day=0;
		while (j<n) {
			int i = 0;
			int s = ar2[i].second;
			while (s>0) {
				if (ar2[i].first<ar[i]) {
					i++;
					break;
				}
				j++;
				s--;
			}
			if (i > m) {
				day = -1;
				break;
			}
			day++;
		}
		cout << day << "\n";
	}
}
