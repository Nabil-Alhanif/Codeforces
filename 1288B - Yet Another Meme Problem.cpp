#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		long long n, m, count=0;
		cin >> n >> m;
		for (int i = 9; i <= m; i=i*10+9) {
			count++;
		}
		count*=n;
		cout << count << "\n";
	}
	
}
