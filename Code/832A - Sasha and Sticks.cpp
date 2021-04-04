#include <bits/stdc++.h>
using namespace std;
int main() {
	long long n,k;
	cin>>n>>k;
	n%=(k+k);
	if(n<k) {
		cout<<"NO\n";
	} else cout<<"YES\n";
}
