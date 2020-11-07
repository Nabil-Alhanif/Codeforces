#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll n,m,z;
	cin>>n>>m>>z;
	ll time=n*m/__gcd(n,m);
	cout<<z/time<<"\n";
}
