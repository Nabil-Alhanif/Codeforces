#include <bits/stdc++.h>
using namespace std;
int main() {
	map<int,int> m;
	int ans=0,n;
	cin>>n;
	while (n--) {
		int tmp;
		cin>>tmp;
		m[tmp]++;
		ans=max(ans,m[tmp]);
	}
	cout<<ans<<" "<<m.size()<<"\n";
}
