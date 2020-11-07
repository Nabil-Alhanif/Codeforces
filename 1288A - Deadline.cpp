#include <bits/stdc++.h>
using namespace std;

inline void getDays(int x, int d, int*p) {
	int tmp = d/(x+1);
	if (tmp*(x+1)!=d) tmp++;
	*p=x+tmp;
}

int main() {
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		bool bisa=0;
		if (d<=n) {
			bisa=1;
		}
		int total;
		for (int i = 1; i <= n; i++) {
			getDays(i, d, &total);
			if (total<=n) {
				bisa=1;
				break;
			}
		}
		if (bisa) {
			cout << "YES\n";
			continue;
		}
		cout << "NO\n";
	}
}
