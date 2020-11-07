#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll size, x, ans=0;
		cin >> size >> x;
		string s;
		cin >> s;
		ll dp[size+1];
		dp[0]=0;
		bool b1=false;ll maks=INT_MIN;
		for (int i = 1; i <= size; i++) {
			dp[i]=dp[i-1];
			if (s[i-1]=='0')dp[i]++;
			else dp[i]--;
			if (dp[i]==x)b1=true;
		}
		if (dp[size]==0) {
			if (b1)cout << "-1\n";
			else if (x!=0)cout << "0\n";
			else cout << "1\n";
		} else {
			if (x==0)ans++;
			for (int i = 1; i <= size; i++) {
				ll b = (x-dp[i])/dp[size];
				if (b*dp[size]==x-dp[i]&&b>=0) ans++;
			}
			cout << ans << "\n";
		}
		
;	}
}
