#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,u;
	double ans=-1;
	cin>>n>>u;
	int ar[n];
	int Ei,Ej,Ek;
	for (int i=0;i<n;i++)
		cin>>ar[i];
	for (int i=0;i<n-2;i++)
	{
		Ei=ar[i];
		int l=i+1,r=n-1,mid=0,pk=0;
		while (l<=r)
		{
			mid=(l+r)/2;
			if (ar[mid]==Ei+u)
			{
				Ek=ar[mid];
				pk=mid;
				break;
			}
			if (ar[mid]>Ei+u)
				r=mid-1;
			if (ar[mid]<Ei+u)
			{
				Ek=ar[mid];
				pk=mid;
				l=mid+1;
			}
		}
		//cout<<Ei<<" "<<Ek<<" "<<pk<<"\n";
		if (pk-i<2)
			continue;
		double tmpAns=(((double)Ek)-((double)ar[i+1]))/(((double)Ek)-((double)Ei));
		ans=max(ans,tmpAns);
	}
	cout<<fixed<<setprecision(12)<<ans<<"\n";
}
