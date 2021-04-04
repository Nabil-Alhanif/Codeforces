#include <bits/stdc++.h>
using namespace std;
int main() {
	map<pair<int,int>,int>m;
	int n,ans=1;
	cin>>n;
	while (n--) {
		int a,b;
		cin>>a>>b;
		m[{a,b}]++;
		ans=max(ans,m[{a,b}]);
	}
	cout<<ans<<"\n";
}
