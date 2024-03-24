#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int r1,c1,r2,c2;
    cin>>r1>>c1>>r2>>c2;
    vector<vector<char>>land(n,vector<char>(n));
    vector<vector<int>>cor(n,vector<int>(n));
    vector<vector<bool>>visit(n,vector<bool>(n));
    map<int,vector<pair<int,int>>>landType;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            cin>>land[i][j];
    int curLand=1;
    queue<pair<int,int>>curPost;
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<n;++j)
        {
            if (!visit[i][j]&&land[i][j]=='0')
            {
                curPost.push({i,j});
                visit[i][j]=1;
                while (!curPost.empty())
                {
                    pair<int,int>curPos=curPost.front();
                    cor[curPos.first][curPos.second]=curLand;
                    landType[curLand].push_back({curPos.first,curPos.second});
                    curPost.pop();
                    if (curPos.first-1>=0)
                    {
                        if (!visit[curPos.first-1][curPos.second]&&land[curPos.first-1][curPos.second]=='0')
                        {
                            visit[curPos.first-1][curPos.second]=1;
                            curPost.push({curPos.first-1,curPos.second});
                        }
                    }
                    if (curPos.first+1<n)
                    {
                        if (!visit[curPos.first+1][curPos.second]&&land[curPos.first+1][curPos.second]=='0')
                        {
                            visit[curPos.first+1][curPos.second]=1;
                            curPost.push({curPos.first+1,curPos.second});
                        }
                    }
                    if (curPos.second-1>=0)
                    {
                        if (!visit[curPos.first][curPos.second-1]&&land[curPos.first][curPos.second-1]=='0')
                        {
                            visit[curPos.first][curPos.second-1]=1;
                            curPost.push({curPos.first,curPos.second-1});
                        }
                    }
                    if (curPos.second+1>=0)
                    {
                        if (!visit[curPos.first][curPos.second+1]&&land[curPos.first][curPos.second+1]=='0')
                        {
                            visit[curPos.first][curPos.second+1]=1;
                            curPost.push({curPos.first,curPos.second+1});
                        }
                    }
                }
                curLand++;
            }
        }
    }
    /*
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
            cout<<cor[i][j];
        cout<<"\n";
    }
    */
    int firstLand=cor[r1-1][c1-1];
    int secondLand=cor[r2-1][c2-1];
    int ans=INT_MAX;
    for (auto i:landType[firstLand])
        for (auto j:landType[secondLand])
            ans=min(ans,((i.first-j.first)*(i.first-j.first)+(i.second-j.second)*(i.second-j.second)));
    cout<<ans<<"\n";
}