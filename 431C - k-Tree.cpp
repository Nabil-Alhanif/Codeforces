#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int n,k,d,ans;
int ar[101][2];
int dfs(int x, bool bisa)
{
	if (ar[x][bisa])return ar[x][bisa];
	if (x<d&&!bisa)return ar[x][bisa]=0;
	for (int i=1;i<=k&&i<=x;i++)
	{
		ar[x][bisa]+=dfs(x-i,(bisa||i>=d));
		ar[x][bisa]%=mod;
	}
	return ar[x][bisa];
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k>>d;
	ar[0][1]=1;
	cout<<dfs(n,0)<<"\n";
}
