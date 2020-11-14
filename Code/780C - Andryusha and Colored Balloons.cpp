#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,ans=1;
    cin>>n;
    vector<vector<int>>graph(n+1);
    vector<bool>visit(n+1);
    vector<int>color(n+1);
    for (int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    queue<pair<int,int>>q;
    color[1]=1;
    visit[1]=1;
    int curC=2;
    for (auto i:graph[1])
    {
        visit[i]=1;
        color[i]=curC;
        ans=max(ans,color[i]);
        curC++;
        q.push({1,i});
    }
    while (!q.empty())
    {
        int kakek=q.front().first,bapak=q.front().second;
        q.pop();
        curC=1;
        for (auto i:graph[bapak])
        {
            if (!visit[i])
            {
                visit[i]=1;
                while (curC==color[bapak]||curC==color[kakek])
                    curC++;
                color[i]=curC;
                ans=max(ans,color[i]);
                curC++;
                q.push({bapak,i});
            }
        }
    }
    cout<<ans<<"\n";
    for (int i=1;i<=n;i++)
        cout<<color[i]<<" ";
    cout<<"\n";
}