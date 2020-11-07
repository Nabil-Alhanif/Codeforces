#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);
	deque<ll> dq;
	ll n;
	cin>>n;
	for (int i = 0; i < n; i++) {
		ll tmp;
		cin>>tmp;
		dq.push_back(tmp);
	}
	ll s=0,d=0;
	for (int i=0;i<n;i++) {
		ll tmp=0;
		if(dq.front()>dq.back()) {
			tmp=dq.front();
			dq.pop_front();
		} else {
			tmp=dq.back();
			dq.pop_back();
		}
		if(i%2==0)s+=tmp;
		else d+=tmp;
	}
	cout<<s<<" "<<d<<"\n";
}
