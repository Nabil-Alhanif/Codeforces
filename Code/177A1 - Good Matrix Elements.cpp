#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,ans=0;
	cin>>n;
	for (int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int tmp;
			cin>>tmp;
			if(i==j||j==n-1-i||i==n/2||j==n/2)ans+=tmp;
		}
	}
	cout<<ans<<"\n";
}
