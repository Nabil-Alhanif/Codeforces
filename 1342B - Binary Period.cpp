#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		string s;
		cin>>s;
		bool c1=0,c2=0;
		for (auto i:s)
		{
			if (i=='0')c1=1;
			if (i=='1')c2=1;
		}
		if (c1&&c2)
		{
			int si=s.size();
			if (s[0]=='0')
			{
				for (int i=0;i<si;i++)cout<<"01";cout<<"\n";
			} else
			{
				for (int i=0;i<si;i++)cout<<"10";cout<<"\n";
			}
		} else cout<<s<<s<<"\n";
	}
}
