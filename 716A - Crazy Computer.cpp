#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,c,fin=0,last=0;
	cin>>n>>c;
	while (n--){
		int now;
		cin>>now;
		if(now-last>c)fin=0;
		last=now;
		fin++;
	}
	cout<<fin<<"\n";
}
