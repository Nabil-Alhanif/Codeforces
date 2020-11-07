#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,ans=0;
	cin>>n;
	for (int i=1;i<1000;i++)
	{
		if (i<10)
		{
			ans++;
			if(ans==n)
			{
				ans=i;
				break;
			}
		} else if (i<100)
		{
			ans+=2;
			if(ans>=n)
			{
				if(ans==n)
				{
					ans=i%10;
				} else {
					ans=i/10;
				}
				break;
			}
		} else {
			ans+=3;
			if (ans>=n)
			{
				if(ans==n)
				{
					ans=i%10;
				} else if (ans==n+1)
				{
					ans=i/10;
					ans%=10;
				} else {
					ans=i/100;
				}
				break;
			}
		}
	}
	cout<<ans<<"\n";
}
