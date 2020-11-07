#include <bits/stdc++.h>
using namespace std;
int n, m;
int kucing[100005];
vector<int> nyambung[100005];
int cek(int x, int past, int kuc) {
	if (kucing[x]==0)kuc=0;
	if (nyambung[x].size()==1&&nyambung[x][0]==past) {
		return 1;
	}
	int tmp=0;
	for (auto i:nyambung[x]) {
		if (kucing[i]+kuc<=m&&i!=past) {
			tmp+=cek(i, x, kucing[i]+kuc);
		}
	}
	return tmp;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> kucing[i];
	}
	for (int i = 0; i < n-1; i++) {
		int x, y;
		cin >> x >> y;
		nyambung[x].push_back(y);
		nyambung[y].push_back(x);
	}
	int ans=0;
	for (auto i:nyambung[1]) {
		if (kucing[1]+kucing[i]<=m) {
			ans+=cek(i, 1, kucing[1]+kucing[i]);
		}
	}
	cout << ans << "\n";
}
