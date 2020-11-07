#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--) {
		ll n;
		cin>>n;
		ll ar[n];
		map<ll,ll> m;
		bool mungkin=1;
		for (int i = 0; i < n; i++) {
			cin>>ar[i];
			m[ar[i]]++;
			if(m[ar[i]]>2) {
				mungkin=0;
			}
		}
		if(!mungkin) {
			cout<<"0\n";
			continue;
		}
		vector<ll> a,b,c,d;
		map<ll,bool> a1,a2,a3,a4;
		bool ada=1,adaLagi=1;
		int i=0;
		for (i;i<n;i++) {
			if(!a1[ar[i]]) {
				a1[ar[i]]=1;
				a.push_back(ar[i]);
			} else {
				break;
			}
		}
		for (i;i<n;i++) {
			if(!a2[ar[i]]) {
				a2[ar[i]]=1;
				b.push_back(ar[i]);
			} else {
				break;
			}
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		if(a.empty()||b.empty()) {
			ada=0;
		}
		if(a.size()+b.size()!=n) {
			ada=0;
		}
		if(a.size()!=a[a.size()-1]) {
			ada=0;
		}
		if(b.size()!=b[b.size()-1]) {
			ada=0;
		}
		i=n-1;
		for (i;i>=0;i--) {
			if(!a3[ar[i]]) {
				a3[ar[i]]=1;
				c.push_back(ar[i]);
			} else break;
		}
		for (i;i>=0;i--) {
			if(!a4[ar[i]]) {
				a4[ar[i]]=1;
				d.push_back(ar[i]);
			} else break;
		}
		sort(c.begin(),c.end());
		sort(d.begin(),d.end());
		if(c.empty()||d.empty()) {
			adaLagi=0;
		}
		if(c.size()+d.size()!=n) {
			adaLagi=0;
		}
		if(c.size()!=c[c.size()-1]) {
			adaLagi=0;
		}
		if(d.size()!=d[d.size()-1]) {
			adaLagi=0;
		}
		if(ada&&adaLagi) {
			if(a.size()!=d.size()) {
				cout<<2<<"\n";
				cout<<a.size()<<" "<<b.size()<<"\n";
				cout<<d.size()<<" "<<c.size()<<"\n";
			} else {
				cout<<1<<"\n";
				cout<<a.size()<<" "<<b.size()<<"\n";
			}
		} else if (ada&&!adaLagi) {
			cout<<1<<"\n";
			cout<<a.size()<<" "<<b.size()<<"\n";
		} else if (!ada&&adaLagi) {
			cout<<1<<"\n";
			cout<<d.size()<<" "<<c.size()<<"\n";
		} else if(!ada&&!adaLagi) {
			cout<<0<<"\n";
		}
	}
}
