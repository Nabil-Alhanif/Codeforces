#include <bits/stdc++.h>
using namespace std;
int main() {
	map<char,int>m;
	m['q']=9;m['r']=5;m['b']=3;m['n']=3;m['p']=1;m['k']=0;
	int b=0,w=0;
	for (int i = 0; i < 8; i++) {
		for (int i = 0; i < 8; i++) {
			char c;
			cin>>c;
			if (c>='A'&&c<='Z') {
				c=tolower(c);
				w+=m[c];
			} else if (c>='a'&&c<='z') {
				b+=m[c];
			}
		}
	}
	//cout<<w<<" "<<b<<"\n";
	if (w>b)cout<<"White\n";
	else if (w==b)cout<<"Draw\n";
	else cout<<"Black\n";
}
