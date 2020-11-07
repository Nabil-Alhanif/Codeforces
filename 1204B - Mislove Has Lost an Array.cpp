#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,l,r;
	cin>>n>>l>>r;
	ll mins=pow(2,l)-1+(n-l);
	ll maks=pow(2,r)-1+(n-r)*pow(2,r-1);
	cout<<mins<<" "<<maks<<"\n";
}
