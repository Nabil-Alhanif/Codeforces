#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	if (n==1)cout<<"1\n";
	else if (n==2)cout<<"5\n";
	else {
		long long ans=5;
		for (int i = 3; i <= n; i++) {
			ans+=4*(i-1);
		}
		cout<<ans<<"\n";
	}
}
