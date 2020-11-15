#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,m;
    cin>>n>>m;
    vector<ll>defeat(n+1);
    set<ll>participant;
    set<ll>::iterator itl,itu;
    for (int i=1;i<=n;i++)
        participant.insert(i);
    while (m--)
    {
        ll l,r,x;
        cin>>l>>r>>x;
        itl=participant.lower_bound(l);
        itu=participant.upper_bound(r);
        for (set<ll>::iterator it=itl;it!=itu;it++)
            defeat[*it]=x;
        participant.erase(itl,itu);
        //cout<<*itu<<"\n";
        if (participant.size())
            participant.insert(--itu,x);
        else participant.insert(x);
        /*
        std::cout << "Current Knight Participant:";
        for (std::set<ll>::iterator it=participant.begin(); it!=participant.end(); ++it)
            std::cout << ' ' << *it;
        cout<<"\nCurrent Winner:";
        for (auto i:defeat)
            cout<<i<<" ";
        std::cout << '\n';
        */
    }
    for (int i=1;i<=n;i++)
        if (defeat[i]!=i)
            cout<<defeat[i]<<' ';
        else cout<<0<<" ";
    cout<<"\n";
}