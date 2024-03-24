#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,p=0;string a,b;
	vector<int>dif;
	vector<char>difC;
	cin>>n>>a>>b;
	for (int i=0;i<n;i++)
	{
		if (a[i]!=b[i])
		{
			dif.push_back(i);
			difC.push_back(a[i]);
		}
	}
	int size=dif.size();
	for (int i=0;i<size;i++)
	{
		if (dif[i]==dif[i+1]-1&&difC[i]!=difC[i+1])
		{
			i++;
			p++;
		}
		else
			p++;
	}
	cout<<p<<"\n";
}
