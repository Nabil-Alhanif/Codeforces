#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin>>s;
	int size=s.size();
	vector<char>v;
	for (int i = 0; i < size; i++) {
		if (s[i]=='Q'||s[i]=='A')v.push_back(s[i]);
	}
	int ans=0;
	size=v.size();
	for (int i = 0; i < size-2; i++) {
		if (v[i]=='Q') {
			for (int j = i+1; j<size-1;j++) {
				if(v[j]=='A') {
					for (int k=j+1;k<size;k++) {
						if (v[k]=='Q') {
							ans++;
						}
					}
				}
			}
		}
	}
	cout<<ans<<"\n";
}
