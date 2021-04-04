#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	int ar[n+1];
	ar[0]=-1;
	int c=0,maks=0,pS=INT_MAX,pE=INT_MIN;
	for (int i = 1; i <= n; i++) {
		cin>>ar[i];
		if (ar[i]==0) {
			pS=min(pS,i);
			pE=max(pE,i);
		}
		if (ar[i]==1)c++;
		else c=0;
		maks=max(maks,c);
	}
	cout<<max(maks,n-pE+pS-1)<<"\n";
}
