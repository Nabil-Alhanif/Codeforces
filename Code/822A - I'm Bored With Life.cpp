#include <bits/stdc++.h>
using namespace std;
int main() {
	int a,b,fact=1;
	cin>>a>>b;
	for (int i=2;i<=min(a,b);i++) {
		fact*=i;
	}
	cout<<fact<<"\n";
}
