#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	pair<int,int> ar[n];
	for (int i = 1; i<=n;i++) {
		int tmp;
		cin>>tmp;
		ar[i-1]={tmp,i};
	}
	sort(ar,ar+n);
	for (int i = 0; i*2<n; i++) {
		cout<<ar[i].second<<" "<<ar[n-i-1].second<<"\n";
	}
}
