#include <bits/stdc++.h>
using namespace std;
bool prime[100001];
void sieve() {
	prime[0]=1;
	prime[1]=1;
	for (int i = 2;i*i<=100001;i++) {
		if(!prime[i]) {
			for (int j=i*i;j<=100001;j+=i) {
				prime[j]=1;
			}
		}
	}
}
int main() {
	sieve();
	int n,m;
	cin>>n>>m;
	for (int i = n+1;i<=m;i++) {
		if (!prime[i]&&i!=m) {
			cout<<"NO\n";
			return 0;
		} else if (!prime[i]&&i==m) {
			cout<<"YES\n";
			return 0;
		}
	}
	cout<<"NO\n";
}
