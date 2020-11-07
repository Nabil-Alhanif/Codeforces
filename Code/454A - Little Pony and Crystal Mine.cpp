#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i+=2) {
		int tmp = n-i;
		tmp/=2;
		cout<<string(tmp,'*')<<string(i,'D')<<string(tmp,'*')<<"\n";
	}
	for (int i = n-2; i>=1; i-=2) {
		int tmp = n-i;
		tmp/=2;
		cout<<string(tmp,'*')<<string(i,'D')<<string(tmp,'*')<<"\n";
	}
}
