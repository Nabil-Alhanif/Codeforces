#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);
	ll t;
	cin >> t;
	while (t--) {
		ll n, maks=INT_MIN, mins=INT_MAX,dif=INT_MIN;
		bool isNotMin=false;
		cin>>n;
		ll ar[n];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
			if (ar[i]!=-1) {
				if (i>0) {
					if (ar[i-1]==-1) {
						mins=min(ar[i],mins);
						maks=max(ar[i],maks);
					} else {
						dif=max(dif, abs(ar[i]-ar[i-1]));
					}
				}
				isNotMin=true;
			} else {
				if (i>0) {
					if (ar[i-1]!=-1) {
						mins=min(mins,ar[i-1]);
						maks=max(maks,ar[i-1]);
					}
				}
			}
		}
		ll ans = ((maks-mins)%2==0?(maks-mins)/2:(maks-mins)/2+1);
		if (!isNotMin) {
			cout<<"0 0\n";
			continue;
		}
		if (dif>=ans) {
			cout<<dif<<" "<<maks-ans<<"\n";
			continue;
		} else {
			cout<<ans<<" "<<maks-ans<<"\n";
			continue;
		}
	}
}
