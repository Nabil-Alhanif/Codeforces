#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<char, ll> ing;
int main() {
	string burger;
	cin >> burger;
	ll size = burger.length();
	for (ll i = 0; i < size; i++) {
		ing[burger[i]]++;
	}
	ll have[3];
	ll need[3];
	for (int i = 0; i < 3; i++) {
		cin >> have[i];
	}
	ll total=0;
	for (int i = 0; i < 3; i++) {
		cin >> need[i];
	}
	total+=need[0]*ing['B'];
	total+=need[1]*ing['S'];
	total+=need[2]*ing['C'];
	ll rubles;
	cin >> rubles;
	ll l = 0, r = 1e13;
	ll answer=0;
	while (l<=r) {
		ll mid = (l+r)/2;
		ll coin1 = (mid*ing['B'])-have[0];
		ll coin2 = (mid*ing['S'])-have[1];
		ll coin3 = (mid*ing['C'])-have[2];
		if (coin1<0)coin1=0;
		if (coin2<0)coin2=0;
		if (coin3<0)coin3=0;
		ll coin = need[0]*coin1 + need[1]*coin2 + need[2]*coin3;
		if (coin <= rubles) {
			l=mid+1;
			answer=max(answer, mid+((rubles-coin)/total));
		} else if (coin>rubles) {
			r=mid-1;
		}
	}
	cout << answer << "\n";
}
