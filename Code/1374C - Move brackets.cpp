#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		int n;string s;
		cin>>n>>s;
		for (int i=0;i<n-1;i++)
		{
			if (s[i]=='('&&s[i+1]==')')
			{
				n-=2;
				s.erase(i,2);
				i-=2;
			}
			//cout<<s<<"\n";
		}
		cout<<n/2<<"\n";
	}
}
