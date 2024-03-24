#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin>>ar[i];
	}
	cout<<ar[1]-ar[0]<<" "<<ar[n-1]-ar[0]<<"\n";
	for (int i = 1;i<n-1;i++){
		cout<<min(ar[i]-ar[i-1],ar[i+1]-ar[i])<<" "<<max(ar[i]-ar[0],ar[n-1]-ar[i])<<"\n";
	}
	cout<<ar[n-1]-ar[n-2]<<" "<<ar[n-1]-ar[0]<<"\n";
}
