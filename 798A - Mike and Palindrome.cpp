#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin>>s;
	int size=s.size();
	bool iya=0,b=0;;
	for (int i=0,j=size-1;i<=j;i++,j--) {
		if (s[i]!=s[j]) {
			if(!iya)iya=1;
			else {
				b=1;
				iya=0;
				break;
			}
		}
	}
	if(!b&&!iya) {
		if(size%2)iya=1;
	}
	cout<<(iya?"YES":"NO")<<"\n";
}
