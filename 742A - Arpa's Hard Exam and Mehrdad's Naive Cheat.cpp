#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	if(n==0){
		cout<<"1\n";
		return 0;
	}
	n%=4;
	if (n==0)n=4;
	int ans=pow(8,n);
	ans%=10;
	cout<<ans<<"\n";
}
