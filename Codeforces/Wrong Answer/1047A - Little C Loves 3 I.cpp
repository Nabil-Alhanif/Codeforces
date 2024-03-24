#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	int a=n/3,b=n/3,c=n/3;
	n%=3;
	if (n==0) {
		if (a%3) {
			cout<<a<<" "<<b<<" "<<c<<"\n";
		} else {
			cout<<a-1<<" "<<b-1<<" "<<c+2<<"\n";
		}
	} else if(n==1) {
		if (a%3) {
			if (a%3==1) {
				cout<<a+1<<" "<<b<<" "<<c<<"\n";
			} else {
				cout<<a-1<<" "<<b-1<<" "<<c+3<<"\n";
			}
		} else {
			cout<<a-1<<" "<<b-2<<" "<<c+4<<"\n";
		}
	} else {
		if (a%3) {
			if (a%3==1) {
				cout<<a<<" "<<b+1<<" "<<c+1<<"\n";
			} else {
				cout<<a<<" "<<b-1<<" "<<c+3<<"\n";
			}
		} else {
			cout<<a-1<<" "<<b+1<<" "<<c+2<<"\n";
		}
	}
}
