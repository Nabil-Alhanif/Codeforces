#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while (t--) {
		int n,m;
		cin>>n>>m;
		cout<<string(m,'B')<<"\n";
		n--;
		while (n--) {
			cout<<"B"<<string(m-1,'W')<<"\n";
		}
	}
}
