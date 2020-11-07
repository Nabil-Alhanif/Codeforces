#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,ans=INT_MAX;
	cin>>n;
	for (int i = 1; i*i<= n; i++) {
		if (!(n%i)) {
			ans=min(ans,(i+(n/i))*2);
		}
	}
	cout<<ans<<"\n";
}
