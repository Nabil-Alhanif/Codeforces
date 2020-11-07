#include<bits/stdc++.h>
using namespace std;
string month[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
int main()
{
	string s;
	int n;
	cin>>s>>n;
	for (int i=0;i<12;i++)
	{
		if (month[i]==s)
		{
			cout<<month[(i+n)%12]<<"\n";
			return 0;
		}
	}
}
