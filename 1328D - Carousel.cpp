#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--) {
		ll n,maks=1;
		cin>>n;
		ll ar[n],ans[n];
		bool beda=false;
		for (int i = 0; i < n; i++) {
			cin>>ar[i];
			if (i!=0) {
				if(ar[i]!=ar[i-1]) beda=true;
			}
		}
		if (!beda) {
			cout<<"1\n";
			cout<<1;
			for(int i = 1; i < n; i++) {
				cout<<" 1";
			} cout<<"\n";
		} else {
			if (n%2==0) {
				cout<<"2\n";
				cout<<1;
				for (int i = 1; i<n;i++) {
					if (i%2==1)cout<<" 2";
					else cout<<" 1";
				}cout<<"\n";
			} else {
				bool himpit=false;
				for (int i = 1; i < n; i++) {
					if (ar[i]==ar[i-1]||ar[0]==ar[n-1]) {
						himpit=true;
						break;
					}
				}
				if (himpit)  {
					bool ket=false;
					cout<<"2\n";
					ans[0]=1;
					cout<<1;
					for (int i = 1; i < n; i++) {
						if(ans[i-1]==1)ans[i]=2;
						else ans[i]=1;
						if (!ket) {
							if(ar[i]==ar[i-1]&&!ket) {
								ans[i]=ans[i-1];
								ket=true;
							}
						} else {
							if (ans[i-1]==1)ans[i]=2;
							else ans[i]=1;
						}
						cout<<" "<<ans[i];
					} cout<<"\n";
				} else {
					cout<<"3\n";
					for (int i = 0; i < n-1; i++) {
						if(i%2==0)cout<<"1 ";
						else cout<<"2 ";
					} cout<<"3\n";
				}
			}
		}
	}
}
