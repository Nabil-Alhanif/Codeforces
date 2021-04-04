#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	int ar[n+1]={0},ar2[n+1]={0};
	int i,j;
	for (i = 1; i <= n; i++) {
		cin>>ar[i];
		ar2[i]=ar[i];
	}
	sort(ar2,ar2+n+1);
	for (i=1;i<=n;i++) {
		if (ar[i]!=ar2[i]||i==n)break;
	}
	for (j=n;j>=i;j--){
		if (ar[j]!=ar2[j]||j==i)break;
	}/*
	if (i==j) {
		cout<<"yes\n";
		cout<<"1 1\n";
		return 0;
	}*/
	bool kebalik=true;
	for (int k=i+1;k<=j;k++){
		if(ar[k]>ar[k-1]) {
			cout<<"no\n";
			return 0;
		}
	}
	cout<<"yes\n";
	cout<<i<<" "<<j<<"\n";
}
