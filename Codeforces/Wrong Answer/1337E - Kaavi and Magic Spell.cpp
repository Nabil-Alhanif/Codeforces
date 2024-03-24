#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long ll;
ll n,m,ans=0;
string s,t;
void cek(string x, ll pos) {
	//cout<<pos<<" "<<x<<"\n";
	ll tmp=x.size();
	if (tmp>=m) {
		string s2=x.substr(0,m);
		//cout<<s<<"\n";
		if (s2==t)ans++;
	}
	ans%=MOD;
	if (pos==n)return;
	//cout<<"\n";
	cek(x+s[pos],pos+1);
	cek(s[pos]+x,pos+1);
}
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s>>t;
	n=s.size();
	m=t.size();
	cek(s.substr(0,1),1);
	cout<<ans*2<<"\n";
}
