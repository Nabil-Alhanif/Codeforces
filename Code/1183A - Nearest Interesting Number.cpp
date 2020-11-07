#include <bits/stdc++.h>
using namespace std;
bool bagiEmpat(int x) {
	int sum=0;
	while (x>0) {
		sum+=x%10;
		x/=10;
	}
	return (sum%4);
}
int main() {
	int x;
	cin>>x;
	while (bagiEmpat(x)) x++;
	cout<<x<<"\n";
}
