#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,sum=0,last=0,most=0;
	cin>>n;
	while (n--) {
		int now;
		cin>>now;
		if (now>last)sum++;
		else sum=1;
		last=now;
		most=max(most,sum);
	}
	cout<<most<<"\n";
}
