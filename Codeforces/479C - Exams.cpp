#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll n,lastExam=0;
	cin>>n;
	pair<ll,ll> ar[n];
	for (int i = 0; i < n; i++) {
		ll a, b;
		cin>>a>>b;
		ar[i]={a,b};
	}
	sort(ar,ar+n);
	for (int i = 0; i < n;i++) {
		if(lastExam<=ar[i].second) {
			lastExam=ar[i].second;
		} else {
			lastExam=ar[i].first;
		}
	}
	cout<<lastExam<<"\n";
}
