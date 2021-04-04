#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,k;
	cin>>n>>k;
	map<int,int> m;
	for (int i = 1; i <= n; i++) {
		int tmp;
		cin>>tmp;
		m[tmp]=i;
	}
	if (m.size()<k) {
		cout<<"NO\n";
		return 0;
	}
	int c=0;
	cout<<"YES\n";
	for (auto&n:m) {
		if(c==k)break;
		cout<<n.second;
		if (c<k-1)cout<<" ";
		c++;
	}
}
