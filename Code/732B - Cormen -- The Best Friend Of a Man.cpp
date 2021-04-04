#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,k,sum=0;
	cin>>n>>k;
	int ar[n];
	for (int i = 0;i<n;i++) {
		cin>>ar[i];
		if(i!=0) {
			if(ar[i]+ar[i-1]<k) {
				sum+=k-(ar[i]+ar[i-1]);
				ar[i]+=k-(ar[i]+ar[i-1]);
			}
		}
	}
	cout<<sum<<"\n";
	for (int i = 0; i < n; i++) {
		cout<<ar[i];
		if(i==n-1)cout<<"\n";
		else cout<<" ";
	}
}
