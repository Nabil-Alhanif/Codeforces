#include <bits/stdc++.h>
using namespace std;
int main() {
	int x,odd=0,even=0;
	cin>>x;
	for (int i = 1;i*i<=x;i++) {
		if(x%i==0) {
			(i%2==0?even++:odd++);
			if(x/i!=i) {
				((x/i)%2==0?even++:odd++);
			}
		}
	}cout<<(odd==even?"yes\n":"no\n");
	//cout<<odd<<" "<<even<<"\n";
}
