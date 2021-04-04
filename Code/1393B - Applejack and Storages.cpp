#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ar[100005],q2,q4,q6,q8;
int main()
{
	ll n,tmp,q;char c;
	cin>>n;
	while (n--)
	{
		cin>>tmp;
		ar[tmp]++;
		if (ar[tmp]==2)q2++;
		if (ar[tmp]==4)
		{
			q2--;
			q4++;
		}
		if (ar[tmp]==6)
		{
			q4--;
			q6++;
		}
		if (ar[tmp]==8)
		{
			q6--;
			q8++;
		}
	}
	//cout<<ar[1]<<" "<<ar[2]<<"\n";
	//cout<<q2<<" "<<q4<<" "<<q6<<" "<<q8<<"\n";
	cin>>q;
	while (q--)
	{
		cin>>c>>tmp;
		if (c=='+')
		{
			ar[tmp]++;
			if (ar[tmp]==2)q2++;
			if (ar[tmp]==4)
			{
				q2--;
				q4++;
			}
			if (ar[tmp]==6)
			{
				q4--;
				q6++;
			}
			if (ar[tmp]==8)
			{
				q6--;
				q8++;
			}
		}
		else
		{
			ar[tmp]--;
			//cout<<tmp<<" "<<ar[tmp]<<"\n";
			if (ar[tmp]==1)q2--;
			if (ar[tmp]==3)
			{
				q2++;
				q4--;
			}
			if (ar[tmp]==5)
			{
				q4++;
				q6--;
			}
			if (ar[tmp]==7)
			{
				q6++;
				q8--;
			}
		}
		//cout<<q2<<" "<<q4<<" "<<q6<<" "<<q8<<"\n";
		if (q8)
		{
			cout<<"YeS\n";
			continue;
		}
		if (q6&&(q2||(q4||q6>=2)))
		{
			cout<<"YEs\n";
			continue;
		}
		if (q4&&(q4>=2||q2>=2))
		{
			cout<<"YES\n";
			continue;
		}
		cout<<"NO\n";
	}
}
