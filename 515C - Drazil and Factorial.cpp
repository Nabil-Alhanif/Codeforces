#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	string s,ans;
	cin>>ans;
	for (int tmp = 0;tmp<n;tmp++) {
		int i=ans[tmp]-'0';
		if (i==2)s+="2";
		if (i==3)s+="3";
		if (i==4)s+="322";
		if (i==5)s+="5";
		if (i==6)s+="53";
		if (i==7)s+="7";
		if (i==8)s+="7222";
		if (i==9)s+="7332";
	}
	sort(s.begin(),s.end(),greater<char>());
	cout<<s<<"\n";
}
