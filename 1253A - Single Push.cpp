#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		ll ar[n], start=-1, pos, count=0, dp[n];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		for (int i = 0; i < n; i++) {
			ll tmp;
			cin >> tmp;
			if (tmp-ar[i]!=0) {
				if (start==-1)start=i;
				pos=i;
				count+=tmp-ar[i];
			}
			dp[i]=tmp-ar[i];
		}
		bool bisa=true;
		if (start==-1) {
			cout << "YES\n";
		} else {
			if (count%(pos-start+1)!=0||count<0||count/(pos-start+1)!=dp[start]) {
				cout << "NO\n";
			} else {
				ll tmp = count/(pos-start+1);
				for (int i = start; i <= pos; i++) {
					if (dp[i]!=tmp) {
						bisa=false;
						break;
					}
				}
				if (bisa)cout << "YES\n";
				else cout << "NO\n";
			}
		}
	}
}
