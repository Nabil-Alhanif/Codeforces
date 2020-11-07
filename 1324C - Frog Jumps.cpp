#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int size = s.size();
		int a=-1, b=0,ans=0;
		for (int i = 0; i < size; i++) {
			if (s[i]=='R') {
				b=i;
				ans=max(ans, b-a);
				a=i;
			}
		}
		ans = max(ans, size-a);
		cout << ans <<"\n";
	}
}
