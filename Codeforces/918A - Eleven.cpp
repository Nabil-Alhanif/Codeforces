#include<bits/stdc++.h>
using namespace std;
int fib[1001];
int main()
{
	fib[1]=1;
	fib[2]=1;
	for (int i=3;i<=1000;i++)fib[i]=fib[i-1]+fib[i-2];
	int n;
	cin>>n;
	string name=string(n,'o');
	for (int i=1;fib[i]<=n;i++)
	{
		name[fib[i]-1]='O';
	}
	cout<<name<<"\n";
}
