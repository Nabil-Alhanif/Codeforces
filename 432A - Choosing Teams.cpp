#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m, ans=0;
	cin >> n >> m;
	while (n--) {
		int tmp;
		cin >> tmp;
		if (tmp+m<=5) {
			ans++;
		}
	}
	ans/=3;
	cout << ans << "\n";
}
