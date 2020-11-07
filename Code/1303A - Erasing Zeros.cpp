#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		ll size=s.length(), ans=0, p1=-1,p2=-1;
		bool ada=false;
		for (ll i = 0; i < size; i++) {
			if (s[i]=='1'){
				p1=i;
				ada=true;
				break;
			}
		}
		if (ada) {
			for (ll i = size-1; i >= p1; i--)  {
				if (s[i]=='1') {
					p2=i;
					break;
				}
			}
			for (ll i = p1; i <= p2; i++) {
				if (s[i]=='0')ans++;
			}
		}
		cout << ans <<"\n";
	}
}
