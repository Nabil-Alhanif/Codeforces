#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	deque<ll>dq;
	ll n,k;
	cin>>n>>k;
	map<ll,bool>m;
	while (n--) {
		ll id;
		cin>>id;
		if(!m[id]) {
			m[id]=1;
			if(dq.size()==k) {
				m[dq.back()]=0;
				dq.pop_back();
			}
			dq.push_front(id);
		}
	}
	cout<<dq.size()<<"\n";
	while (!dq.empty()) {
		cout<<dq.front()<<" ";
		dq.pop_front();
	}
}
