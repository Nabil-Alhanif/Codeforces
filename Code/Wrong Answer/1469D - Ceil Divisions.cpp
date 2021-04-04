#include <bits/stdc++.h>
#define fi first
#define sc second
#define mp make_pair
using namespace std;
typedef long long ll;

ll tc, n;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> tc;
	while(tc--){
		cin >> n;
		if(n % 2 == 0){
			cout << n - 1 << '\n';
			cout << "2 1\n";
			for(int k = 2; k < n; k++){
				cout << k  << ' ' << k + 1 << '\n';
			}
		}
		else{
			cout << (n + 1)/2 << '\n';
			cout << "2 1\n";
			for(int k = 2; k <= (n + 1)/2; k++){
				cout << k*2 - 2 << ' ' << k*2 - 1 << '\n';
			}
		}
	}
}