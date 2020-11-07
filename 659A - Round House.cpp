#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a,b;
	cin>>n>>a>>b;
	for (int i=0;i<abs(b);i++)
	{
		if (b<0)
		{
			a--;
			if (a==0)a=n;
		} else {
			a++;
			if (a==n+1)a=1;
		}
	}
	cout<<a<<"\n";
}
