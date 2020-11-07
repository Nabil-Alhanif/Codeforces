#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int n;string s;
	cin >> n >> s;
	vector<ll> v;
	ll c=0;
	for (int i = 0; i < n; i++) {
		if (s[i]=='B')c++;
		if (s[i]!='B'||i==n-1) {
			if (c!=0) {
				v.push_back(c);
				c=0;
			}
		}
	}
	cout << v.size()<<"\n";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
		if (i!=v.size()-1)cout << " ";
	}
	cout << "\n";
}
