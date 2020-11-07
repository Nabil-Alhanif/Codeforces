#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		if(n==1) cout<<"-1\n";
		else {
			cout<<string(n-1,'9')<<8<<"\n";
		}
	}
}
