#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ar[100005];
int main() {
	ll n, m;
	cin >> n >> m;
	while (m--) {
		ll a,b;
		cin >> a >> b;
		ar[a]++;
		ar[b]++;
	}
	ll c=0, d=0 ,e=0;
	for (int i = 1; i <= n; i++) {
		if (ar[i]==1)c++;
		else if (ar[i]==2)d++;
		else if (ar[i]==n-1)e++;
	}
	if (c==2&&d==n-2)cout<<"bus topology\n";
	else if (d==n)cout<<"ring topology\n";
	else if (c==n-1&&e==1)cout<<"star topology\n";
	else cout << "unknown topology\n";
}
