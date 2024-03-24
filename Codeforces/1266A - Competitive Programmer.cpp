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
		int ans=0;
		bool t1=0,t2=0;
		for (auto i:s)
		{
			if(i=='0')
			{
				if(t1)t2=1;
			} else {
				if(!((i-'0')%2))t2=1;
			}
			//cout<<(i-'0')<<"\n";
			if(i=='0')t1=1;
			ans+=(i-'0');
		}
		//cout<<ans<<"\n";
		if(!(ans%3)&&t1&&t2)cout<<"red\n";
		else cout<<"cyan\n";
	}
}
