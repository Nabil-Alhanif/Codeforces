#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll n;
	cin>>n;
	ll ar[n];
	map<ll,ll> m;
	vector<ll>v;
	for (int i = 0; i < n; i++) {
		cin>>ar[i];
	}
	sort(ar,ar+n);
	if(n==1) {
		cout<<"-1\n";
		return 0;
	}
	bool sama=1,gitu=0;
	ll dif=INT_MAX,pos=-1;
	for (int i = 1; i < n; i++) {
		if (ar[i]==ar[i-1]) {
			gitu=1;
		}
		ll tmp=ar[i]-ar[i-1];
		dif=min(dif,tmp);
		m[tmp]++;
		if(m[tmp]==1)v.push_back(tmp);
		if(v.size()>2) {
			cout<<"0\n";
			return 0;
		}
		if(v.size()>1)sama=false;
	}
	if(sama&&dif==0) {
		cout<<"1\n";
		cout<<ar[0]<<"\n";
		return 0;
	}
	if(gitu) {
		cout<<0<<"\n";
		return 0;
	}
	if(sama&&n>2) {
		cout<<2<<"\n";
		cout<<ar[0]-dif<<" "<<ar[n-1]+dif<<"\n";
	} else if (sama&&n==2) {
		if(dif%2==0) {
			cout<<3<<"\n";
			cout<<ar[0]-dif<<" "<<ar[1]-dif/2<<" "<<ar[1]+dif<<"\n";
		} else {
			cout<<2<<"\n";
			cout<<ar[0]-dif<<" "<<ar[n-1]+dif<<"\n";
		}
	} else {
		sort(v.begin(),v.end());
		if(v[1]!=v[0]*2) {
			cout<<"0\n";
			return 0;
		} else {
			if(m[v[1]]>1) {
				cout<<"0\n";
				return 0;
			} else {
				cout<<1<<"\n";
				for (int i = 1; i < n; i++) {
					if(ar[i]-ar[i-1]==v[1]) {
						cout<<ar[i]-v[0]<<"\n";
						return 0;
					}
				}
			}
		}
	}
}
