#include <bits/stdc++.h>
using namespace std;
inline int solve(int a, int b, int c) {
	int count=0;
	for (int i = 0; i < c; i++) {
		if (((a >> i) & 1) != ((b >> i) & 1)) { 
            count++; 
        }
	}
	return count;
}
int main() {
	int k, n, m, me,ans=0;
	cin>>k>>m>>n;
	int ar[m];
	for (int i = 0; i < m; i++) {
		cin>>ar[i];
	}
	cin>>me;
	for (int i = 0; i < m; i++) {
		if (solve(ar[i],me,k)<=n) ans++;
	}
	cout<<ans<<"\n";
}
