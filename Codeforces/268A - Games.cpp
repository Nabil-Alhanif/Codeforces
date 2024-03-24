#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int n, ans=0;
	cin >> n;
	int ar[n][2];
	for (int i = 0; i < n; i++) {
		cin >> ar[i][0] >> ar[i][1];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i!=j) {
				if (ar[i][0]==ar[j][1])ans++;
			}
		}
	}
	cout << ans << "\n";
}
