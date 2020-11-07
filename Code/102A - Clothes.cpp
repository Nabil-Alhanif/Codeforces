#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, ans=-1;
	cin >> n >> m;
	map<int, bool> ar[n+1];
	int p[n+1];
	for (int i = 1; i <= n; i++){
		cin >> p[i];
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >>a >> b;
		ar[a][b]=true;
		ar[b][a]=true;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {
			if (ar[i][j]) {
				for (int k = j+1; k <= n; k++) {
					if (ar[i][k]&&ar[k][j]) {
						int tmp = p[i]+p[j]+p[k];
						if (ans==-1)ans=tmp;
						else {
							ans=min(tmp, ans);
						}
					}
				}
			}
		}
	}
	cout << ans << "\n";
}
