#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n,ans=0;
    cin>>n;
    set<ll>group[2];
    vector<vector<ll>>graph(n+1);
    //vector<pair<ll,ll>>antri(n-1);
    map<int,bool>m;
    for (ll i=1;i<n;i++)
    {
        ll a,b;
        cin>>a>>b;
        //antri[i-1]={min(a,b),max(a,b)};
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    //sort(antri.begin(),antri.end());
    stack<pair<ll,ll>>q;
    q.push({1,1});
    group[0].insert(1);
    while (!q.empty())
    {
        pair<ll,ll> cur=q.top();
        m[cur.first]=1;
        q.pop();
        for (auto i:graph[cur.first])
        {
            if (!m[i])
            {
                m[i]=1;
                group[cur.second].insert(i);
                q.push({i,(cur.second+1)%2});
            }
        }
    }
    ll s=group[1].size();
    /*
    cout<<"Size "<<s<<"\n";
    cout<<"Group[0]: ";
    for (auto i:group[0])
        cout<<i<<" ";
    cout<<"\n";
    cout<<"Group[1]: ";
    for (auto i:group[1])
        cout<<i<<" ";
    cout<<"\n";
    cout<<"Counting:\n";
    */
    for (auto i:group[0])
    {
        //cout<<i<<" "<<graph[i].size()<<"\n";
        ans+=s-graph[i].size();
    }
    cout<<ans<<"\n";
}