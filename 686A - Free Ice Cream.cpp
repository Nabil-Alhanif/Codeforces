#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);
	ll n,x,kids=0;
	cin>>n>>x;
	while (n--) {
		char c;ll tmp;
		cin>>c>>tmp;
		if (c=='+')x+=tmp;
		else {
			if (x>=tmp)x-=tmp;
			else kids++;
		}
	}
	cout<<x<<" "<<kids<<"\n";
}
