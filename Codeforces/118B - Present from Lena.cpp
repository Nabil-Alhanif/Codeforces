#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	for (int i =0; i<=n;i++) {
		cout<<string(max(0,(n-i)*2),' ');
		for (int j=0;j<=i;j++){
			if(j)cout<<" ";
			cout<<j;
		}
		for (int j=i-1;j>=0;j--)cout<<" "<<j;
		cout<<"\n";
	}
	for (int i=n-1;i>=0;i--) {
		cout<<string(max(0,(n-i)*2),' ');
		for (int j=0;j<=i;j++){
			if(j)cout<<" ";
			cout<<j;
		}
		for (int j=i-1;j>=0;j--)cout<<" "<<j;
		cout<<"\n";
	}
}
