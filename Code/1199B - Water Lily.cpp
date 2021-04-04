#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long h,l;
	cin>>h>>l;
	double ans=(l*l-h*h);
	ans/=2*h;
	cout<<setprecision(6)<<fixed<<ans<<"\n";
}
