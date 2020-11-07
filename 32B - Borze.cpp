#include <bits/stdc++.h>
using namespace std;
int main() {
	string s,ans;
	cin>>s;
	int size=s.size();
	for (int i = 0; i < size; i++) {
		if (s[i]=='.')ans+='0';
		else {
			if (s[i]==s[i+1]) {
				ans+='2';
			} else ans+='1';
			i++;
		}
	}
	cout<<ans<<"\n";
}
