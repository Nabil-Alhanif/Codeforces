#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--) {
		ll a,b,c,d,x,y,x1,y1,x2,y2,dX,dY;
		cin>>a>>b>>c>>d>>x>>y>>x1>>y1>>x2>>y2;
		dX=a-b;
		dY=c-d;
		//cout<<"x: "<<x-dX<<" y: "<<y-dY<<" ";
		if(x>=x1&&x<=x2&&y>=y1&&y<=y2) {
			bool b1=1,b2=1;
			if(a>=1||b>=1) {
				if(!(abs(x1-x)>=1||abs(x2-x)>=1)) {
					b1=0;
				}
			}
			if(c>=1||d>=1) {
				if(!(abs(y1-y)>=1||abs(y2-y)>=1)) {
					b2=0;
				}
			}
			if(x-dX>=x1&&x-dX<=x2&&y-dY>=y1&&y-dY<=y2&&b1&&b2) {
				cout<<"Yes\n";
				continue;
			}
		}cout<<"No\n";
	}
}
