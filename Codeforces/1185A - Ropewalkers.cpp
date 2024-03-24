#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	int ar[3]={a,b,c};
	sort(ar,ar+3);
	cout<<((ar[1]-ar[0]<d)?d-(ar[1]-ar[0]):0)+((ar[2]-ar[1]<d)?d-(ar[2]-ar[1]):0)<<"\n";
}
