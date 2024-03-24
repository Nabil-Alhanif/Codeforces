#include <bits/stdc++.h>
using namespace std;
int main() {
	int x,y,z,a,b,c;
	cin>>x>>y>>z>>a>>b>>c;
	if (a<x) {
		cout<<"NO\n";
		return 0;
	} else a-=x;
	int p=a+b;
	if (p<y) {
		cout<<"NO\n";
		return 0;
	} else p-=y;
	int t=p+c;
	if (t<z) {
		cout<<"NO\n";
		return 0;
	}
	//cout<<a<<" "<<p<<" "<<t<<"\n";
	cout<<"YES\n";
}
