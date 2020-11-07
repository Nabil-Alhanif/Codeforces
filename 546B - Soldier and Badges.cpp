#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int ar[n],ans=0;
	map<int,int>m;
	for (int i=0;i<n;i++)
	{
		cin>>ar[i];
		m[ar[i]]++;
	}
	sort(ar,ar+n);
	for (int i=0;i<n;i++)
	{
		if (m[ar[i]]!=1)
		{
			for (int j=ar[i]+1;;j++)
			{
				ans++;
				if (!m[j])
				{
					m[j]++;
					m[ar[i]]--;
					break;
				}
			}
		}
	}
	cout<<ans<<"\n";
}
