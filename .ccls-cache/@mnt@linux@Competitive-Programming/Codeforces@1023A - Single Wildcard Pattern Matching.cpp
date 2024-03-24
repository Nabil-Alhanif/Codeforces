#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(0);
	ll n,m;string s,t;bool ast=0;
	cin>>n>>m>>s>>t;
	int l=0,r=0;
	for (int i=0,j=0;i<n;i++,j++)
	{
		if(s[i]=='*')
		{
			ast=1;
			break;
		}
		if (s[i]==t[j])l++;
		else break;
	}
	for (int i=n-1,j=m-1;i>=0;i--,j--)
	{
		if (s[i]=='*')
		{
			ast=1;
			break;
		}
		if (s[i]==t[j]&&j>=l)r++;
		else break;
	}
	//cout<<l<<" "<<r<<"\n";
	if (!ast&&n<m)return (cout<<"NO\n",0);
	if (l+r==n||l+r==n-(int)ast) return (cout<<"YES\n",0);
	return (cout<<"NO\n",0);
}
