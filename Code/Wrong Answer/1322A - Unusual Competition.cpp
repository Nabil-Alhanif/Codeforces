#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;string s;
	cin>>n>>s;
	if(n%2) {
		cout<<"-1\n";
		return 0;
	}
	int ans=0;
	for (int i = 0; i < n; i++) {
		if(i%2==0) {
			if(s[i]!='(')ans++;
		} else {
			if(s[i]!=')')ans++;
		}
	}
	cout<<ans<<"\n";
}
