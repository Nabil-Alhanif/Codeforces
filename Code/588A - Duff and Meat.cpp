#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);
	ll n,price=0;
	cin>>n;
	pair<ll,ll> meat[n];
	for (int i=0;i<n;i++) {
		cin>>meat[i].first>>meat[i].second;
	}
	int i=0,j=0;
	for (j; j<=n; j++) {
		if (meat[j].second<meat[i].second||j==n) {
			for (int k=i;k<j;k++) {
				price+=meat[k].first*meat[i].second;
			}
			i=j;
		}
	}
	cout<<price<<"\n";
}
