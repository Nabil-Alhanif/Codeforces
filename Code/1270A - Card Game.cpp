#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while (t--) {
		int n,a,b;
		cin>>n>>a>>b;
		int ma=0,mb=0;
		while(a--) {
			int scoreA;
			cin>>scoreA;
			ma=max(ma,scoreA);
		}
		while (b--) {
			int scoreB;
			cin>>scoreB;
			mb=max(mb,scoreB);
		}
		cout<<(ma>mb?"YES\n":"NO\n");
	}
}
