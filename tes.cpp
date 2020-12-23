#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll atep (ll a, ll b)
{
	return ((a+b-1)/b);
}
bool check(ll m, ll w, ll p, ll n, ll r)
{
	if (m>=atep(n,w))
		return true;
	ll curProd=m*w;
	r--;
	if (!(r))
		return false;
	while (true)
	{
		ll dif=n-curProd;
		ll rndLef=atep(dif,m*w);
		if (rndLef<=r)
			return true;
		if (curProd<p)
		{
			dif=p-curProd;
			rndLef=atep(dif,m*w);
			r-=rndLef;
			if (r<1)
				return false;
			curProd+=rndLef*m*w;
		}
		curProd-=p;
		if (m>w)
			w++;
		else
			m++;
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll m,w,p,n;
	cin>>m>>w>>p>>n;
	ll l=1,r=1e12,mid;
	while (l<=r)
	{
		mid=(l+r)/2;
		if (check(m,w,p,n,mid))
			r=mid-1;
		else l=mid+1;
	}
	cout<<mid<<"\n";
}