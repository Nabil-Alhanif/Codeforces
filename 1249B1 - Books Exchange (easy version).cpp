#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int q;
	cin>>q;
	while (q--)
	{
		int n;
		cin>>n;
		int ar[n];
		for (int i=0;i<n;i++)cin>>ar[i];
		for (int i=0;i<n;i++)
		{
			int count=1,j=i+1;
			while (ar[j-1]!=i+1)
			{
				j=ar[j-1];
				count++;
			}
			cout<<count<<" ";
		}cout<<"\n";
	}
}
