#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while (t--) {
		ll n,a1=-1,a2=-1;
		cin>>n;
		ll a[n],b[n];
		for (int i = 0; i < n; i++) {
			cin>>a[i];
			if (a1==-1&&a[i]==1)a1=i;
			if (a2==-1&&a[i]==-1)a2=i;
		}
		for (int i = 0; i < n; i++) {
			cin>>b[i];
		}
		bool bisa=1;
		//cout<<a1<<" "<<a2<<"\n";
		for (int i = 0; i < n; i++) {
			if (a[i]>b[i]) {
				if (a2>=i||a2==-1) {
					cout<<"NO\n";
					bisa=0;
					break;
				}
			}
			if(a[i]<b[i]) {
				if (a1>=i||a1==-1) {
					cout<<"NO\n";
					bisa=0;
					break;
				}
			}
		}
		if (bisa)cout<<"YES\n";
	}
}
