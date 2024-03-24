#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		int r,g,b,w,o=0;
		cin>>r>>g>>b>>w;
		if (!(r%2)&&!(g%2)&&!(b%2)&&!(w%2))
		{
			cout<<"Yes\n";
			continue;
		}
		if(r%2)o++;
		if(g%2)o++;
		if(b%2)o++;
		if (o%2)
		{
			if (!(w%2))
			{
				cout<<"Yes\n";
				continue;
			}
			else
			{
				if (o==3&&w%2)
				{
					cout<<"Yes\n";
					continue;
				}
			}
		}
		else
		{
			if (w%2&&((r&&g&&b)||o==0))
			{
				cout<<"Yes\n";
				continue;
			}
		}
		cout<<"No\n";
	}
}
