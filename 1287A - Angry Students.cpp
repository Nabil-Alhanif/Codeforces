#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	long t;
	cin >> t;
	while (t--) {
		long size, ans=0, tmp=0;
		string s;
		bool lanjut=false;
		cin >> size >> s;
		for (int i = 0; i < size-1; i++) {
			if (s[i]=='A'&&s[i+1]=='P') {
				tmp=1;
				lanjut=true;
			} else if (lanjut&&s[i+1]=='P') {
				tmp++;
			} else {
				lanjut=false;
				ans = max(ans, tmp);
			}
		}
		ans = max(ans, tmp);
		cout << ans << "\n";
	}
}
