#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Dijkstra{
    ll nVertex,nEdge;
    public:
    vector<vector<pair<ll,ll>>>adjList;
    vector<ll>dist,par;
    vector<bool>vis;

    Dijkstra(ll a, ll b)
    {
        nVertex=a;
        nEdge=b;
        adjList.resize(a);
        dist.resize(a, LLONG_MAX);
        par.resize(a);
        vis.resize(a);
        for (ll i=0;i<b;i++)
        {
            ll u,v,w;
            cin>>u>>v>>w;
            u--;v--;
            adjList[u].push_back({v,w});
            adjList[v].push_back({u,w});
        }
        for (auto i:adjList)
            sort(i.begin(),i.end());
    }

    void DijkstraAlgo()
    {
        //cout<<"ASASAS\n";
        //cout<<nVertex<<" "<<nEdge<<"\n";
        dist[0]=0;
        for (ll i=0;i<nVertex;i++)
        {
            ll localMin=-1;
            for (ll j=0;j<nVertex;j++)
                if (!vis[j]&&(localMin==-1||dist[j]<dist[localMin]))
                    localMin=j;
            if (dist[localMin]==LLONG_MAX)
                break;
            vis[localMin]=1;
            for (auto j:adjList[localMin])
            {
                ll to=j.first,weight=j.second;
                if (dist[localMin]+weight<dist[to])
                {
                    dist[to]=dist[localMin]+weight;
                    par[to]=localMin;
                }
            }
            //cout<<localMin<<" locMin\n";
        }
    }

    void prllTrace()
    {
        DijkstraAlgo();
        if (dist[nVertex-1]==LLONG_MAX)
        {
            cout<<"-1\n";
            return;
        }
        /*
        for (int i=0;i<nVertex;i++)
            cout<<i<<" par "<<par[i]<<"\n";
        */
        vector<ll>path;
        ll i=nVertex-1;
        while (i!=0)
        {
            path.push_back(i+1);
            i=par[i];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        for (auto i:path)
            cout<<i<<" ";
        cout<<"\n";
    }
};
int main()
{
    int a,b;
    cin>>a>>b;
    Dijkstra dijk(a,b);
    dijk.prllTrace();
}