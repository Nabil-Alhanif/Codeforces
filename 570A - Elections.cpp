#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,victory=1,mostVote=0;
	cin>>n>>m;
	int cand[n]{0};
	for (int i=0;i<m;i++)
	{
		int winner=1,maks=0;
		for (int j=1;j<=n;j++)
		{
			int vote;
			cin>>vote;
			if (maks<vote)
			{
				maks=vote;
				winner=j;
			}
		}
		cand[winner-1]++;;
	}
	for (int i=0;i<n;i++)
	{
		if (mostVote<cand[i])
		{
			mostVote=cand[i];
			victory=i+1;
		}
	}
	cout<<victory<<"\n";
}
