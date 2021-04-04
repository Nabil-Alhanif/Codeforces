#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while (t--) {
		ll n;
		double dif=0,most=0;;
		cin>>n;
		double ar[n];
		for (int i = 0; i < n; i++) {
			cin>>ar[i];
			if(i==0)most=ar[i];
			else{
				most=max(most,ar[i]);
				if (ar[i]<most) {
					dif=max(most-ar[i],dif);
				}
			}
		}
		//cout<<dif<<"\n";
		double c=log2(dif+1);
		c=ceil(c);
		cout<<c<<"\n";
	}
}
