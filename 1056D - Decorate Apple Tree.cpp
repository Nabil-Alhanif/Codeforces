#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector <ll> ar[1000000];
ll counting[1000000];
vector<ll> bulb;
int main() {
	ll n;
	cin >> n;
	for (ll i = 2; i <= n; i++) {
		ll tmp;
		cin >> tmp;
		ar[tmp].push_back(i);
	}
	for (ll i = n; i >= 1; i--) {
		ll size = ar[i].size();
		if (size==0) {
			counting[i]=1;	
		}
		else {
			for (int j = 0; j < size; j++) {
				counting[i]+=counting[ar[i][j]];
			}
		}
		bulb.push_back(counting[i]);
	}
	sort(bulb.begin(), bulb.end());
	for (int i = 0; i < n; i++) {
		cout << bulb[i] << " ";
	}
}
