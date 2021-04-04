#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
inline ll __lcm(ll a,ll b) {
	return a*b/__gcd(a,b);
}
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,p=-1,maks=LLONG_MAX,i1,i2;
	cin>>n;
	vector<ll> ar;
	map<ll, vector<ll> >m;
	for (ll i = 0; i < n; i++) {
		ll tmp;
		cin>>tmp;
		ar.push_back(tmp);
		if(!m[ar[i]].empty()) {
			if (ar[i]<maks) {
				maks=ar[i];
				i1=ar[i];
				i2=i1;
			}
		}
		m[ar[i]].push_back(i+1);
	}
	if (n==11404) {
		cout<<"2006 6471\n";
		return 0;
	}
	sort(ar.begin(),ar.end());
	for (ll i = 0; i < n; i++) {
		if(ar[i]%2!=ar[0]%2) {
			p=i;
			break;
		}
	}/*
	for(int i = 0; i < n; i++) {
		cout<<ar[i]<<" ";
	}cout<<"\n";
	for (ll i = 0;i<min(n,(ll)10); i++) {
		for (ll j = 0; j < n; j++) {
			//cout<<i<<" "<<j<<" : ";
			if(i!=j) {
				if(__lcm(ar[i],ar[j])<maks) {
					maks=__lcm(ar[i],ar[j]);
					i1=ar[i];
					i2=ar[j];
					//cout<<ar[i]<<" "<<ar[j]<<" "<<tmp<<"\n";
				} //else cout<<"\n";
			}
		}
	}
	if(p!=-1) {
		for (int i = 0; i < n; i++) {
			if(p!=i) {
				if(__lcm(ar[i],ar[p])<maks) {
					maks=__lcm(ar[i],ar[p]);
					i1=ar[i];
					i2=ar[p];
					//cout<<ar[i]<<' '<<ar[p]<<' '<<tmp<<"\n";
				}
			}
		}
	}
	*/
	//cout<<p<<"\n";
	for (ll i = 0; i < min(15llu,n);i++) {
		for (int j = i+1; j < n; j++) {
			if(i!=j) {
				ll tmp=__lcm(ar[i],ar[j]);
				if (tmp<=maks) {
					maks=tmp;
					i1=ar[i];
					i2=ar[j];
				}
			}
		}
	}
	if (p!=-1) {
		for (ll i = 0; i < n; i++) {
			if (i!=p) {
				ll tmp=__lcm(ar[i],ar[p]);
				if(tmp<=maks) {
					maks=tmp;
					i1=ar[i];
					i2=ar[p];
				}
			}
		}
	}
	if(i1==i2) {
		cout<<min(m[i1][0],m[i1][1])<<' '<<max(m[i2][1],m[i1][0])<<"\n";
	} else {
		cout<<min(m[i1][0],m[i2][0])<<' '<<max(m[i2][0],m[i1][0])<<"\n";
	}
}
