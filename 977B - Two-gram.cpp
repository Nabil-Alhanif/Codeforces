#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,most=0;string s,win;
	cin>>n>>s;
	map<string,int>m;
	for (int i = 0; i < n-1; i++) {
		string s2=s.substr(i,2);
		m[s2]++;
		if (m[s2]>most) {
			most=m[s2];
			win=s2;
		}
	}
	cout<<win<<"\n";
}
