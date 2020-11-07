#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while (t--)
	{
		int n,k,ans=0,tmp=0;
		string s;
		cin>>n>>k>>s;
		tmp=k;
		for (int i=0;i<n;i++)
		{
			char c=s[i];
			if (c=='0')tmp++;
			if (c=='1'||i==n-1)
			{
				if(i==n-1&&c=='0')tmp+=k;
				tmp=max(0,tmp-k);			
				//cout<<tmp<<" "<<i<<" i\n";
				ans+=(tmp/(k+1));
				tmp=0;
			}
		}

		cout<<ans<<"\n";
	}
}
