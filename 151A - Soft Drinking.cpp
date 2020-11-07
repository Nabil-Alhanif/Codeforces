#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, k, l, c, d, p, nl, np;
	cin >> n>>k>>l>>c>>d>>p>>nl>>np;
	c*=d;
	k*=l;
	k/=nl;
	p/=np;
	cout<<(min(c, min(k, p)))/n<<"\n";
}
