#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	while (n--) {
		string s;
		cin>>s;
		map<char,int>m;
		int size=s.size();
		bool con=1;
		if (size==1) {
			cout<<"YES\n";
			continue;
		}
		vector<char>v;
		for (int i = 0; i < size; i++) {
			if (m[s[i]]) {
				con=0;
				break;
			}
			m[s[i]]++;
			v.push_back(s[i]);
		}
		if(!con) {
			cout<<"NO\n";
			continue;
		}
		sort(v.begin(),v.end());
		size=v.size();
		for (int i = 1; i < size; i++) {
			if (v[i]-v[i-1]>1)con=0;
		}
		if (con)cout<<"YES\n";
		else cout<<"NO\n";
	}
}
