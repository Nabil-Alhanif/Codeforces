#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while (t--) {
		char ar[9][9];
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j<9; j++) {
				cin>>ar[i][j];
				if (i==0&&j==0) {
					ar[i][j]+=1;
					if (ar[i][j]==':')ar[i][j]='1';
				}
				if (i==1&&j==4) {
					ar[i][j]+=1;
					if (ar[i][j]==':')ar[i][j]='1';
				}
				if (i==2&&j==8) {
					ar[i][j]+=1;
					if (ar[i][j]==':')ar[i][j]='1';
				}
				if (i==3&&j==1) {
					ar[i][j]+=1;
					if (ar[i][j]==':')ar[i][j]='1';
				}
				if (i==4&&j==5) {
					ar[i][j]+=1;
					if (ar[i][j]==':')ar[i][j]='1';
				}
				if (i==5&&j==6) {
					ar[i][j]+=1;
					if (ar[i][j]==':')ar[i][j]='1';
				}
				if (i==6&&j==2) {
					ar[i][j]+=1;
					if (ar[i][j]==':')ar[i][j]='1';
				}
				if (i==7&&j==3) {
					ar[i][j]+=1;
					if (ar[i][j]==':')ar[i][j]='1';
				}
				if (i==8&&j==7) {
					ar[i][j]+=1;
					if (ar[i][j]==':')ar[i][j]='1';
				}
			}
		}
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout<<ar[i][j];
			}cout<<"\n";
		}
	}
}
