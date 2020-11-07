#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll m, s;
	cin >> m >> s;
	if ((s==0&&m>1)||m==0||s>(m*9))cout << "-1 -1\n";
	else if (s==0&&m==1)cout<<"0 0\n";
	else {
		ll tmp=s/9;
		s%=9;
		if(s==0) {
			tmp--;
			s=9;
		}
		if (m==1)cout << s << " "<<s<<"\n";
		else {
			if (m-tmp>1) cout << 1<<string(m-tmp-2, '0')<<s-1<<string(tmp,'9')<<" ";
			else cout << s<<string(tmp, '9')<<" ";
			cout << string(tmp, '9')<<s<<string(m-tmp-1,'0')<<"\n";
		}
	}
}
