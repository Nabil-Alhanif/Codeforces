#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,ans=0;
	cin>>n;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin>>ar[i];
		if (i!=0) {
			if (ar[i-1]==ar[i]&&ar[i]!=3) {
				ar[i]=0;
			}
			if (ar[i-1]!=ar[i]&&ar[i]==3)ar[i]-=ar[i-1];
		}
		if (!(ar[i]))ans++;
	}
	cout<<ans<<"\n";
}
