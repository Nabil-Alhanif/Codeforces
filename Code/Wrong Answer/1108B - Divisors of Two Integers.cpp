#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,ya=1,x;
	cin>>n;
	map<int,bool>m;
	int ar[n];
	for(int i = 0; i< n; i++) {
		cin>>ar[i];
	}
	sort(ar,ar+n);
	x=ar[n-1];
	for (int i = 0;i < n; i++) {
		if (x%ar[i]||m[ar[i]]) {
			ya=ya*ar[i]/__gcd(ya,ar[i]);
		}
		m[ar[i]]=1;
	}
	cout<<x<<" "<<ya<<"\n";
}
