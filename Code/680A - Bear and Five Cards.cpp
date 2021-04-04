#include <bits/stdc++.h>
using namespace std;
int main()
{
	map<int,int>m;
	int mins=0;
	int ans=0;
	for (int i=0;i<5;i++)
	{
		int tmp;
		cin>>tmp;
		ans+=tmp;
		m[tmp]++;
		if(m[tmp]>=2)
		{
			mins=max(mins, tmp*min(m[tmp],3));
		}
	}
	cout<<ans-mins<<"\n";
}
