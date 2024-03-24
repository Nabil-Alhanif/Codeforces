#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	int ar[n];
	for (int i=0;i<n;i++)cin>>ar[i];
	sort(ar,ar+n);
	cout<<min(ar[n-1]-ar[1],ar[n-2]-ar[0])<<"\n";
}
