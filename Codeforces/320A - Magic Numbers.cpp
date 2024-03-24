#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin>>s;
	int size=s.size();
	int i=0;
	while (i<size) {
		//cout<<size-i<<"\n";
		if (size-i>=3) {
			//cout<<"c1 ";
			if (s[i]=='1'&&s[i+1]=='4'&&s[i+2]=='4') {
				i+=3;
				//cout<<i<<"\n";
				continue;
			}
		}
		if (size-i>=2) {
			//cout<<"c2 ";
			if (s[i]=='1'&&s[i+1]=='4') {
				i+=2;
				//cout<<i<<"\n";
				continue;
			}
		}
		if (size-i>=1) {
			//cout<<"c3 ";
			if (s[i]=='1') {
				i++;
				//cout<<i<<"\n";
				continue;
			} else {
				cout<<"NO\n";
				return 0;
			}
		}
	}
	cout<<"YES\n";
}
