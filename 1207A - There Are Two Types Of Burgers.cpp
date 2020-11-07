#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(a,b) for(int i=a;i<=b;i++)
#define FORBACK(a,b) for(int i=b;i>=a;i--)
#define pb push_back
#define mp make_pair
#define sz size
#define fi first
#define se second
int t,b,p,f,h,c;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>t;
	for(int tc=1;tc<=t;tc++){
		cin>>b>>p>>f;
		cin>>h>>c;
		ll ans=0;
		if(h==c){
			ans+=h*(min(b/2,(p+f)));
		}
		if(h>c){
			ans+=h*(min(b/2,p));
			b=b-2*min(b/2,p);
			ans+=c*(min(b/2,f));
		}
		if(h<c){
			ans+=c*(min(b/2,f));
			b=b-2*min(b/2,f);
			ans+=h*(min(b/2,p));
		}
		cout<<ans<<endl;
	}
}
