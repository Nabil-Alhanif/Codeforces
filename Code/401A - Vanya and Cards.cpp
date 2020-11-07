#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,x,tot=0;
	cin>>n>>x;
	while (n--)
	{
		int tmp;
		cin>>tmp;
		tot+=tmp;
	}
	tot=abs(tot);
	cout<<tot/x+(tot%x?1:0)<<"\n";
}
