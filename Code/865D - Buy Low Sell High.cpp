#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    bool b=0;
    ll n,ans=0;
    cin>>n;
    ll ar[n+1];
    for (int i=0;i<n;i++)
        cin>>ar[i];
    priority_queue<ll,vector<ll>,greater<ll>>pq;
    pq.push(ar[0]);
    for (int i=1;i<n;i++)
    {
        pq.push(ar[i]);
        if (ar[i]>pq.top())
        {
            ans+=ar[i]-pq.top();
            pq.pop();
            pq.push(ar[i]);
        }
    }
    cout<<ans<<"\n";
}