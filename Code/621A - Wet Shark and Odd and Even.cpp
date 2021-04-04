#include <bits/stdc++.h>
using namespace std;
int main() {
	int mins=INT_MAX,n;
	long long ans=0;
	cin>>n;
	while (n--) {
		int tmp;
		cin>>tmp;
		if(tmp%2)mins=min(mins,tmp);
		ans+=tmp;
	}
	if (ans%2)ans-=mins;
	cout<<ans<<"\n";
}
