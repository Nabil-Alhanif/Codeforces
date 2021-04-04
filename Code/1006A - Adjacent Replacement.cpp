#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin>>ar[i];
		if (!(ar[i]%2)) ar[i]--;
	}
	for(int i = 0; i < n; i++) {
		cout<<ar[i]<<" ";
	}cout<<"\n";
}
