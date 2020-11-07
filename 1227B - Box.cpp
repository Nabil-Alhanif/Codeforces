#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		ll ar[n+1],a[n+1];
		bool b[n+1];
		ll maks=0;
		memset(b, 0, sizeof(b));
		memset(a,0,sizeof(a));
		bool k=false;
		for (int i = 1; i <= n; i++) {
			cin >> ar[i];
			if(maks<ar[i])
			{
				b[ar[i]]=true;
				a[i]=ar[i];
				maks=ar[i];
			}
			else if(i>maks)
			{
				k=true;
			}
		}
		ll s=1;
		if (k)cout << "-1\n";
		else {
			for (int i = 1; i <= n; i++) {
				if (a[i]!=0)cout << a[i];
				else {
					while(b[s]==true)
					{
						s++;
					}
					b[s]=true;
					cout << s;
				}
				if (i!=n)cout<< " ";
			} cout << "\n";
		}
	}
}
