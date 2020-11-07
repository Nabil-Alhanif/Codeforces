#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int n;
	cin >> n;
	int a[n],b[n],sA=0,sB=0;
	for (int i = 0; i < n; i++) {
		cin>>a[i];
	}
	for (int i = 0; i < n; i++) {
		cin>>b[i];
	}
	for (int i = 0; i < n; i++) {
		if(a[i]&&!b[i])sA++;
		else if(b[i]&&!a[i])sB++;
	}
	if(!sA)cout<<"-1\n";
	else cout<<(sB/sA)+1<<"\n";
}
