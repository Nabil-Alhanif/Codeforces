#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);
	ll a,b,c1=0,c2=0,c3=0;
	cin>>a>>b;
	for (int i = 1; i <= 6; i++) {
		if (abs(i-a)<abs(i-b))c1++;
		else if (abs(i-a)>abs(i-b))c3++;
		else c2++;
	}
	cout<<c1<<" "<<c2<<" "<<c3<<"\n";
}
