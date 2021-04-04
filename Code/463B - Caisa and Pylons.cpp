#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,ans=0;
	cin>>n;
	while (n--) {
		int height;
		cin>>height;
		ans=max(ans,height);
	}
	cout<<ans<<"\n";
}
