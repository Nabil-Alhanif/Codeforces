#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool prime[1000002];
void sieve() {
	prime[1]=true;
	for (int i = 2; i*i<=1000002; i++) {
		if (!prime[i]) {
			for (int j = i*i; j <= 1000002; j+=i) {
				prime[j]=true;
			}
		}
	}
}
int main() {
	sieve();
	ll n;
	cin >> n;
	for (int i = 1; i <= 1000; i++) {
		if (prime[1+(n*i)]) {
			cout << i << "\n";
			break;
		}
	}
}
