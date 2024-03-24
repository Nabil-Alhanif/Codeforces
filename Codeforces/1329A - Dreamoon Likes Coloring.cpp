#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,m,tot=0;
	cin>>n>>m;
	ll ar[m],ar2[m];
	bool bisa=1;
	for (int i = 0; i < m; i++) {
		cin>>ar[i];
		tot+=ar[i];
		if(i+ar[i]>n) {
			//cout<<ar[i]<<"\n";
			bisa=0;
		}
	}
	if(!bisa) {
		cout<<"-1\n";
		return 0;
	}
	tot=n-tot;
	if(tot>0) {
		cout<<"-1\n";
		return 0;
	}
	tot=abs(tot);
	ll pos=1;
	for (int i=0; i< m; i++) {
		cout<<pos;
		ll tmp=ar[i]-1;
		pos+=tmp;
		if (tot>tmp) {
			tot-=tmp;
			pos-=tmp;
			pos++;
		} else if (tot==tmp) {
			tot=0;
			pos-=tmp;
			pos++;
		} else if (tot<tmp) {
			if(tot>0) {
				pos-=tot;
				tot=0;
				pos++;
			} else {
				pos++;
			}
		}
		if(i<m-1)cout<<" ";
		else cout<<"\n";
	}
}
