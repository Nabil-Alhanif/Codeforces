#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		for (int i=0;i<=c&&c;i++)
			cout<<1;
		for (int i=0;i<=a&&a;i++)
			cout<<0;
		if (a&&c)
		{
			b--;
			for (int i=1;i<=b;i++)
				cout<<i%2;
			cout<<"\n";
		}
		else if (!a&&c)
		{
			for (int i=0;i<b;i++)
				cout<<i%2;
			cout<<"\n";
		}
		else if (a&&!c)
		{
			for (int i=1;i<=b;i++)
				cout<<i%2;
			cout<<"\n";
		}
		else
		{
			cout<<1;
			for (int i=0;i<b;i++)
				cout<<i%2;
			cout<<"\n";
		}
	}
}
