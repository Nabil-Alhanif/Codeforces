#include <bits/stdc++.h>
using namespace std;
int main() {
	int ar[11];
	for (int i = 0; i < 11; i++) {
		cin>>ar[i];
	}
	for (int i = 10; i>= 0; i--) {
		double ans=sqrt(abs(ar[i]))+ar[i]*ar[i]*ar[i]*5;
		if(ans>400) {
			cout<<"f("<<ar[i]<<") = MAGNA NIMIS!\n";
		} else printf("f(%d) = %.2f\n", ar[i], ans);
	}
}
