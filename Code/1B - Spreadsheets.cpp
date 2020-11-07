#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll n;
	cin>>n;
	while (n--) {
		string s;
		cin>>s;
		ll size=s.size();
		if (s[0]=='R'&&s[1]<'A'&&s.find("C")!=string::npos) {
			ll r=0,c=0,i;
			for (i=1;;i++) {
				if (s[i]=='C')break;
				ll lle=s[i]-'0';
				r=r*10+lle;
			}
			i++;
			for (i;i<size;i++) {
				ll lle=s[i]-'0';
				c=c*10+lle;
			}
			//cout<<c<<" "<<r<<"\n";
			string ans;
			while (c>0) {
				ll tmp=c%26;
				if (!(tmp))tmp=26;
				ans=char(64+tmp)+ans;
				c/=26;
				if(tmp==26)c--;
			}
			cout<<ans<<r<<"\n";
		} else {
			string ans;
			ll i=0,r=0,c=0;
			for (i = 0;;i++){
				if(s[i]<'A')break;
				ans+=s[i];
			}
			for (i;i<size;i++){
				ll tmp=s[i]-'0';
				r=r*10+tmp;
			}
			size=ans.size();
			for (ll i = 0;i<size;i++){
				c+=pow(26,size-1-i)*(ll)(ans[i]-'A'+1);
			}
			cout<<"R"<<r<<"C"<<c<<"\n";
		}
	}
}
