#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin>>ar[i];
	}
	map<int,bool> m;
	vector<int>v;
	for (int i = n-1; i >= 0; i--) {
		if (!m[ar[i]]) {
			v.push_back(ar[i]);
		}
		m[ar[i]]=1;
	}
	cout<<v.size()<<"\n";
	for (auto i=v.rbegin();i!=v.rend();i++) {
		cout<<*i<<" ";
	}cout<<"\n";
}
