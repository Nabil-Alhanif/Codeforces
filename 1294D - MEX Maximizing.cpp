#include <bits/stdc++.h>
using namespace std;

int main() {
	int q,x;
	cin >> q >> x;
	map<int,int> m;
	int ans=0;
	while (q--) {
		int tmp;
		cin >> tmp;
		m[tmp%x]++;
		while (m[ans%x]>ans/x) ans++;
		cout << ans << "\n";
	}
	
}
