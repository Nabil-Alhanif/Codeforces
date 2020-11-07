#include <bits/stdc++.h>
using namespace std;
long long dp[100006], a[100006], maks=0;
int main() {
	ios_base::sync_with_stdio(0);
	long long n, size=0, ans=0;
	cin >> n;
	for (long long i = 0;i<n;i++) {
		long long tmp;
		cin >> tmp;
		maks=max(maks,tmp);
		a[tmp]+=tmp;
	}
	dp[0]=0;
	dp[1]=a[1];
	for (long long i = 2; i <= maks; i++) {
		dp[i]=max(dp[i-1], dp[i-2]+a[i]);
	}
	cout << dp[maks] << "\n";
}
