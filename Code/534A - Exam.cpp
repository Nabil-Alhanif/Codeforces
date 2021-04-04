#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,j;
	cin>>n;
	if (n==1||n==2)cout<<"1\n1\n";
	else if (n==3)cout<<"2\n1 3\n";
	else if (n==4)cout<<"4\n3 1 4 2\n";
	else {
		cout<<n<<"\n";
		int p=n-(n%2?0:1);
		for (int i=1;i<=p;i+=2)cout<<i<<" ";
		for (int j=2;j<=n;j+=2)cout<<j<<" ";
	}cout<<"\n";
}
