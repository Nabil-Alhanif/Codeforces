#include <bits/stdc++.h>
using namespace std;
int main() {
	string a, b;
	cin >> a >> b;
	char a1=a[0], b1=b[0];
	int a2=a[1]-'0', b2=b[1]-'0';
	int mh=a1-b1, mv=a2-b2;
	int mo=min(abs(mh),abs(mv));
	int m=max(abs(mh),abs(mv));
	cout<<m<<"\n";
	m-=mo;
	while (mo--) {
		if(mh<=0) cout<<"R";
		else cout<<"L";
		if(mv<=0)cout<<"U\n";
		else cout<<"D\n";
	}
	while(m--){
		if(mh<0&&abs(mh)>abs(mv)) cout<<"R\n";
		else if(mh>0&&abs(mh)>abs(mv)) cout<<"L\n";
		if(mv<0&&abs(mv)>abs(mh))cout<<"U\n";
		else if(mv>0&&abs(mv)>abs(mh)) cout<<"D\n";
	}
}
