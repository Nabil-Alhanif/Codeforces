#include<bits/stdc++.h>
using namespace std;
int main()
{
	int q;
	cin>>q;
	while (q--)
	{
		int n,posn,posx;
		bool iya=0;
		cin>>n;
		int ar[n*2];
		for (int i=0;i<n;i++)
		{
			cin>>ar[i];
			if (ar[i]==1)posx=i;
			if (ar[i]==n)posn=i;
		}
		if (n==1)
		{
			cout<<"YES\n";
			continue;
		}
		for (int i=n;i<n*2;i++)ar[i]=ar[i-n];
		//cout<<posx<<" "<<posn<<"\n";
		bool iya2=1;
		for (int i=posx+1;i<posx+n;i++)
		{
			if (ar[i]!=ar[i-1]+1)
			{
				iya2=0;
				break;
			}
		}
		if (iya2)iya=1;
		iya2=1;
		for (int i=posn+1;i<posn+n;i++)
		{
			if (ar[i]!=ar[i-1]-1)
			{
				//cout<<i<<"\n";
				iya2=0;
				break;
			}
		}
		if (iya2)iya=1;
		if (ar[posx+n-1]!=2&&ar[posx+n-1]!=n){iya=0;}
		//for (int i=0;i<n*2;i++)cout<<ar[i]<<" ";cout<<"\n";
		cout<<(iya?"YES\n":"NO\n");
	}
}
