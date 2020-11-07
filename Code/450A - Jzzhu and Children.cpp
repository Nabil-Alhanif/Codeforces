#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,m;
	cin>>n>>m;
	pair<int,int> ar[n];
	for (int i = 0; i < n; i++) {
		int a;
		cin>>a;
		a=(a/m)+(a%m?1:0);
		ar[i]={a,i};
	}
	sort(ar,ar+n);
	cout<<ar[n-1].second+1<<"\n";
}
