#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,m;
	cin>>n>>m;
	char ar[n][m];
	for (int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin>>ar[i][j];
			if (ar[i][j]=='-')continue;
			if(i%2) {
				if(j%2) {
					ar[i][j]='B';
				} else ar[i][j]='W';
			} else {
				if (j%2) {
					ar[i][j]='W';
				} else ar[i][j]='B';
			}
		}
	}
	for (int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<ar[i][j];
		}cout<<"\n";
	}
}
