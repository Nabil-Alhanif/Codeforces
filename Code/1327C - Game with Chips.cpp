#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);
	int n, m, k;
	cin>>n>>m>>k;
	for (int i = 0; i < k; i++) {
		int a, b;
		cin>>a>>b;
	}
	for (int i = 0; i < k; i++) {
		int a,b;
		cin>>a>>b;
	}
	int count=n+m-2;
	count+=n*m;
	cout<<count<<"\n";
	cout<<string(n-1,'U')<<string(m-1,'L');
	for(int i = 0; i < n; i++) {
		if(i%2==0)cout<<string(m-1,'R');
		else cout<<string(m-1,'L');
		cout<<"D";
	}
	cout<<"\n";
}
