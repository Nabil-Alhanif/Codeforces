#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long ll;
int main()
{
	ll a,b,n;
	cin>>a>>b>>n;
	ll ar[6]={a-b,a,b,b-a,-a,-b};
	cout<<(ar[n%6]+(2*mod))%mod<<"\n";
}
