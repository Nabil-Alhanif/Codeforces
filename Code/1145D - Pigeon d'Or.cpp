#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,mins=INT_MAX;
	cin>>n;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin>>ar[i];
		mins=min(mins,ar[i]);
	}
	cout<<(mins^ar[2])+2<<"\n";
}
