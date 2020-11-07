#include <bits/stdc++.h>
using namespace std;
int main() {
	int r,c,ans=0;;
	cin>>r>>c;
	char ar[r][c];
	bool vis[r][c];
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin>>ar[i][j];
			vis[i][j]=false;
		}
	}
	for (int i = 0; i < r; i++) {
		bool jahat=0,visi=0;
		for (int j = 0; j < c; j++) {
			if (ar[i][j]=='S'){
				jahat=1;
				break;
			}
			if (!vis[i][j])visi=1;
		}
		if (!jahat&&visi) {
			for (int j = 0; j < c; j++) {
				if (!vis[i][j]) {
					//cout<<i<<" "<<j<<"\n";
					ans++;
				}
				vis[i][j]=true;
			}
		}
	}
	for (int j = 0; j < c; j++) {
		bool jahat=0,visi=0;
		for (int i = 0; i < r; i++) {
			if (ar[i][j]=='S') {
				jahat=1;
				break;
			}
			if (!vis[i][j])visi=1;
		}
		if(!jahat&&visi) {
			for (int i = 0; i < r; i++) {
				if(!vis[i][j]) {
					//cout<<i<<" "<<j<<"\n";
					ans++;
				}
				vis[i][j]=true;
			}
			//ans++;
		}
	}
	cout<<ans<<"\n";
}
