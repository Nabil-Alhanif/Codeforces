#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isVisit[10005];
int main() {
	ll n, m;
	cin >> n >> m;
	queue<pair<ll, ll> > s;
	s.push(make_pair(n, 0));
	ll answer=INT_MAX;
	while (!s.empty()) {
		if (s.front().first<=0) {
			s.pop();
		} else {
			ll pos=s.front().first, ans=s.front().second;
			isVisit[pos]=1;
			s.pop();
			if (pos==m)  {
				answer=min(answer, ans);
			} else {
				if (pos<m) {
					if (pos*2<=10000) {
						if (!isVisit[pos*2]) {
							s.push(make_pair(pos*2, ans+1));
							isVisit[pos*2]=1;
						}
					}
					if (!isVisit[pos-1]&&pos-1>0) {
						s.push(make_pair(pos-1, ans+1));
						isVisit[pos-1]=1;
					}
				} else {
					if (!isVisit[pos-1]&&pos-1>0) {
						s.push(make_pair(pos-1, ans+1));
						isVisit[pos-1]=1;
					}
				}
			}
		}
	}
	cout << answer << "\n";
}
