#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int a, b;
	cin>>a>>b;
	int tmp=6-(max(a,b))+1;
	if (tmp==1)cout<<"1/6\n";
	else if (tmp==2)cout<<"1/3\n";
	else if(tmp==3)cout<<"1/2\n";
	else if(tmp==4)cout<<"2/3\n";
	else if(tmp==5)cout<<"5/6\n";
	else if(tmp==6)cout<<"1/1\n";
	else cout<<"0/1\n";
}
