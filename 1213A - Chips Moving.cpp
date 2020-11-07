#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,one=0,two=0;
	cin>>n;
	while (n--) {
		int tmp;
		cin>>tmp;
		if(tmp%2)one++;
		else two++;
	}
	cout<<min(one,two)<<"\n";
}
