#include <bits/stdc++.h>
using namespace std;
int main() {
	int size;
	string s,ans;
	cin>>size>>s;
	ans=s[0];
	for (int i=1;i<size;i++) {
		if (size%2) {
			if(i%2)ans=s[i]+ans;
			else ans+=s[i];
		} else {
			if(i%2)ans+=s[i];
			else ans=s[i]+ans;
		}
	}
	cout<<ans<<"\n";
}
