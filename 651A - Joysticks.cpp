#include <bits/stdc++.h>
using namespace std;
int main() {
	int a,b,time=0;
	cin>>a>>b;
	while (a&&b) {
		if(a==1&&b==1)break;
		if (a<=b) {
			a++;
			b-=2;
		} else {
			b++;
			a-=2;
		}
		//cout<<a<<" "<<b<<"\n";
		time++;
	}
	cout<<time<<"\n";
}
