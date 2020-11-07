#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		double n;
		cin>>n;
		double tmp=n*n-4*n;
		if (tmp<0)
		{
			cout<<"N\n";
			continue;
		}
		tmp=sqrt(tmp);
		cout<<"Y "<<fixed<<setprecision(9)<<" "<<(n+tmp)/2<<" "<<(n-tmp)/2<<"\n";
	}
}
