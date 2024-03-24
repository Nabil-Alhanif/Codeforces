#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		int n;
		cin>>n;
		int ar[n*2];
		vector<int>ans;
		map<int,bool>m;
		for (int i=0;i<n*2;i++)
		{
			cin>>ar[i];
			if (!m[ar[i]])
			{
				ans.push_back(ar[i]);
				m[ar[i]]=1;
			}
		}
		for (auto i:ans)
			cout<<i<<" ";
		cout<<"\n";
	}
}
