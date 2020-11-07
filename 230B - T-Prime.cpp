#include <bits/stdc++.h> 
#define ll long long
using namespace std;
bool prime[20000005];
ll n = 20000000;
void sieve() { 
    memset(prime, true, sizeof(prime)); 
    for (ll p=2; p*p<=n; p++) {
        if (prime[p] == true) {  
            for (ll i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
}
int main() {
	sieve();
	ll t;
	scanf("%lld", &t);
	ll query[t+1];
	for (int i = 1; i <= t; i++) {
		scanf("%lld", &query[i]);
	}
	for (int i = 1; i <= t; i++) {
		if (query[i] == 1) {
			printf("NO\n");
			continue;
		}
		ll tmp = pow(query[i], 0.5);
		if (tmp * tmp!=query[i]) {
			printf("NO\n");
			continue;
		}
		if (prime[tmp]) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}
