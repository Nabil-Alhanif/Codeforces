#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,ans=0,nMax=0,people=0;
    cin>>n;
    map<ll,ll> year;
    while (n--)
    {
        int birth,death;
        cin>>birth>>death;
        year[birth]++;
        year[death]--;
    }
    for (auto i:year)
    {
        people+=i.second;
        if (nMax<people)
        {
            nMax=people;
            ans=i.first;
        }
    }
    cout<<ans<<" "<<nMax<<"\n";
}