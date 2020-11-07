#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,m,ma=0,mb=0;
	cin>>n;
	while (n--) {
		int tmp;
		cin>>tmp;
		ma=max(ma,tmp);
	}
	cin>>m;
	while(m--){
		int tmp;
		cin>>tmp;
		mb=max(mb,tmp);
	}
	cout<<ma<<" "<<mb<<"\n";
}
