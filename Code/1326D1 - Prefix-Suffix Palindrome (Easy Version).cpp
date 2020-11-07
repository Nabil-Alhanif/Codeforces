#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
inline ll bigMod(ll base, ll exp) {
	if(exp==0)return 1;
	if (exp==1)return base;
	ll tmp=bigMod(base,exp/2);
	if(exp%2==0) return (tmp%MOD*tmp%MOD)%MOD;
	else return (((tmp%MOD*tmp%MOD)%MOD)*base%MOD)%MOD;
}
inline ll MMI(ll size) {
	return bigMod(size,MOD-2);
}
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while (t--) {
		string s;
		cin >> s;
		int size=s.length();
		string a, b;
		if(s[0]==s[size-1]) {
			string s2=s;
			reverse(s2.begin(),s2.end());
			if(s==s2) {
				cout<<s<<"\n";
				continue;
			}
		}
		for (int i=0, j=size-1; i<j; ++i,--j) {
			if(s[i]==s[j]) {
				a+=s[i];
				b=s[j]+b;
			} else break;
		}
		ll p1=a.size();
		if(p1!=0) {
			s.erase(0,p1);
			s.erase(size-p1-p1,p1);
		}
		size-=2*p1;
		ll prefix[size+1],suffix[size+1],power[size+1];
		power[0]=1;
		prefix[0]=0;
		suffix[0]=0;
		if(size>0) {
			power[1]=101;
			prefix[1]=s[0];
			suffix[1]=s[size-1];
		}
		ll tmpp=size-2;
		for (int i = 2; i <= size; ++i) {
			power[i]=(power[i-1]%MOD*101%MOD)%MOD;
			prefix[i]=(prefix[i-1]%MOD+(s[i-1]%MOD*power[i-1]%MOD)%MOD)%MOD; 
			if(tmpp>=0){suffix[i]=(suffix[i-1]%MOD+(s[tmpp]%MOD*power[i-1]%MOD)%MOD)%MOD;--tmpp;}
		}
		ll newSize=0, pS=-1,posA=0,posB=size-1;
		for (int i=0,tmp=size-1;i<=tmp;++i,--tmp) {
			if (s[i]==s[posA]&&i+1>newSize) {
				ll pref=((prefix[i+1]-prefix[posA]+MOD)%MOD*MMI(power[posA])%MOD)%MOD;
				ll suff=((suffix[size-posA]-suffix[size-i-1]+MOD)%MOD*MMI(power[size-i-1])%MOD)%MOD;
				if(pref==suff) {
					//if(i+1>newSize) {
						newSize=i+1;
						pS=0;
					//}
				}
			}else {
				if (s[i]==s[posB]&&size-i>newSize) {
					ll pref=((prefix[posB+1]-prefix[i]+MOD)%MOD*MMI(power[i])%MOD)%MOD;
					ll suff=((suffix[size-i]-suffix[size-posB-1]+MOD)%MOD*MMI(power[size-posB-1])%MOD)%MOD;
					if(pref==suff) {
						//if(size-i>newSize) {
							newSize=size-i;
							pS=i;
							break;
						//}
					}
				}
			}
			if (s[tmp]==s[posA]&&tmp+1>newSize) {
				ll pref=((prefix[tmp+1]-prefix[posA]+MOD)%MOD*MMI(power[posA])%MOD)%MOD;
				ll suff=((suffix[size-posA]-suffix[size-tmp-1]+MOD)%MOD*MMI(power[size-tmp-1])%MOD)%MOD;
				if(pref==suff) {
					//if(tmp+1>newSize) {
						newSize=tmp+1;
						pS=0;
						break;
					//}
				}
			}else{
				if (s[tmp]==s[posB]&&size-tmp>newSize) {
					ll pref=((prefix[posB+1]-prefix[tmp]+MOD)%MOD*MMI(power[tmp])%MOD)%MOD;
					ll suff=((suffix[size-tmp]-suffix[size-posB-1]+MOD)%MOD*MMI(power[size-posB-1])%MOD)%MOD;
					if(pref==suff) {
						//if(size-tmp>newSize) {
						newSize=size-tmp;
						pS=tmp;
						//}
					}
				}
			}
		}
		string fin=s.substr(pS,newSize);
		cout<<a<<fin<<b<<"\n";
	}
	return 0;
	//ok
}

