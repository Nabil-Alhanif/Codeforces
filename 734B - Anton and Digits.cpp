#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	ll tm=min(a, min(c, d));
	a-=tm;
	ll ans=tm*256;
	ans+=min(a, b)*32;
	cout << ans <<"\n";
	
}
