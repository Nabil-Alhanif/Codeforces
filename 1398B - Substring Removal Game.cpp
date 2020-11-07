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
		int size=s.size();
		int it=0,ans=0;
		vector<int> score;
		for (int i=0;i<size;i++)
		{
			if (s[i]=='1')it++;
			if (s[i]=='0'||i==size-1)
			{
				score.push_back(it);
				it=0;
			}
		}
		sort(score.begin(),score.end(),greater<int>());
		//for (auto i:score)cout<<i<<" ";
		//cout<<"\n";
		size=score.size();
		for (int i=0;i<size;i+=2)
			ans+=score[i];
		cout<<ans<<"\n";
	}
}
