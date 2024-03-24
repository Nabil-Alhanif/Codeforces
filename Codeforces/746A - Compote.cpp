#include <bits/stdc++.h>
using namespace std;
int main() {
	int ans=0,a,b,c;
	cin>>a>>b>>c;
	for (int i = 1; i<= a; i++) {
		if (i*2<=b&&i*4<=c) {
			ans=i*7;
		} else break;
	}
	cout<<ans<<"\n";
}
