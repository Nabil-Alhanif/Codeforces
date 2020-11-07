#include <bits/stdc++.h>
using namespace std;
int main() {
	int c=0,sum=0;
	string s;
	while(getline(cin,s)) {
		if(s[0]=='+')c++;
		else if(s[0]=='-')c--;
		else sum+=c*(s.size()-s.find(':')-1);
	}
	cout<<sum<<"\n";
	return 0;
}
