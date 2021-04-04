#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//asdsadasd
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while (t--) {
		ll n,l,r,c=0;
		cin>>n>>l>>r;
		ll tmp=l;
		ll coun=0;
		ll tmp2=2*(n-1);
		while (tmp>tmp2) {
			tmp-=tmp2;
			coun+=1;
			c+=tmp2;
			tmp2-=2;
			if(tmp==1)break;
		}
		for (int i=1+coun;i<n;i++) {
			for (int j = i+1;j<=n;j++) {
				c++;
				if (c>=l&&c<=r) {
					cout<<i<<" ";
				}else if(c>r)break;
				c++;
				if (c>=l&&c<=r) {
					cout<<j<<" ";
				} else if (c>r)break;
			}
			if(c>r)break;
		}
		c++;
		if (c>=l&&c<=r)cout<<1;
		cout<<"\n";
	}
}
