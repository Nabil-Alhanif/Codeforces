#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,d,sum=0;
	cin>>n>>d;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin>>tmp;
		sum+=tmp;
	}
	d-=sum;
	if (d>=10*(n-1)) {
		cout<<d/5<<"\n";
	} else cout<<"-1\n";
}
