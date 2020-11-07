#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		string s;int n,x;
		cin>>s>>x;
		n=s.size();
		string w=string(n,'1');
		for (int i=0;i<n;i++)
		{
			if (s[i]=='0')
			{
				if (i-x>=0)
					w[i-x]='0';
				if (i+x<n)
					w[i+x]='0';
			}
		}
		bool isValid=1;
		for (int i=0;i<n&&isValid;i++)
		{
			bool b1=0,b2=0;
			if (s[i]=='1')
			{
				if (i-x>=0)
					if (w[i-x]=='1')
						b1=1;
				if (i+x<n)
					if (w[i+x]=='1')
						b2=1;
				isValid=((b1||b2)&&isValid);
			}
		}
		cout<<(isValid?w+"\n":"-1\n");
	}
}
