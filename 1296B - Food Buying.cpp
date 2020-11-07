#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll tmp, ans=0;;
		cin >> tmp;
		while (tmp>0) {
			if (tmp>=10) {
				ll temp;
				temp = tmp/10;
				ans+=tmp-tmp%10;
				tmp%=10;
				tmp+=temp;	
			}
			else {
				ans+=tmp;
				tmp/=10;
			}
		}
		cout << ans << "\n";
	}
}
