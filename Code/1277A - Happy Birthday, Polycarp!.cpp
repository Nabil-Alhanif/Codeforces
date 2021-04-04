#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int ans = 0;
		int size= s.size();
		ans+=(size-1)*9;
		bool bisa=true;
		for (int i = 1; i<size; i++) {
			if (s[i]<s[0]) {
				bisa=false;
				break;
			} else if (s[i]>s[0]) {
				bisa=true;
				break;
			}
		}
		if (bisa) {
			ans+=s[0]-'0';
		} else {
			ans+=s[0]-'0';
			ans--;
		}
		cout <<ans << "\n"
;	}
}
