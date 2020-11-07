#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,won=0;
	cin>>n;
	string win;
	map<string,int>m;
	while (n--) {
		string s;
		cin>>s;
		m[s]++;
		if (m[s]>won){
			won=m[s];
			win=s;
		}
	}
	cout<<win<<"\n";
}
