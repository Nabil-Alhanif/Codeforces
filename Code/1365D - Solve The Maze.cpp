#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<char>>maze(n+2,vector<char>(m+2));
        vector<vector<bool>>posPlace(n+2,vector<bool>(m+2));
        vector<vector<bool>>vis(n+2,vector<bool>(m+2));
        vector<pair<int,int>>goodPos;
        for (int i=0;i<n+2;i++)
        {
            for (int j=0;j<m+2;j++)
            {
                if (i>0&&i<=n&&j>0&&j<=m)
                    cin>>maze[i][j];
                else maze[i][j]='#';
                if (maze[i][j]=='G')
                    goodPos.push_back({i,j});
            }
        }
        bool bisa=1;/*
        for (int i=0;i<n+2;i++)
        {
            for (int j=0;j<m+2;j++)
                cout<<maze[i][j];
            cout<<"\n";
        }*/
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                if (maze[i][j]=='B')
                {
                    if (
                        maze[i-1][j]=='G'||
                        maze[i+1][j]=='G'||
                        maze[i][j-1]=='G'||
                        maze[i][j+1]=='G'
                    )
                    {
                        //cout<<"NO is because of bad people.\n";
                        bisa=0;
                    }
                    if (maze[i-1][j]=='.')
                        maze[i-1][j]='#';
                    if (maze[i+1][j]=='.')
                        maze[i+1][j]='#';
                    if (maze[i][j-1]=='.')
                        maze[i][j-1]='#';
                    if (maze[i][j+1]=='.')
                        maze[i][j+1]='#';
                }
            }
        }
        queue<pair<int,int>>q;
        if (maze[n][m]!='#')
            q.push({n,m});
        while (!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            posPlace[row][col]=1;
            q.pop();
            vis[row][col]=1;
            if (row-1>0&&maze[row-1][col]!='#'&&!vis[row-1][col])
            {
                vis[row-1][col]=1;
                q.push({row-1,col});
            }
            if (row+1<=n&&maze[row+1][col]!='#'&&!vis[row+1][col])
            {
                vis[row+1][col]=1;
                q.push({row+1,col});
            }
            if (col-1>0&&maze[row][col-1]!='#'&&!vis[row][col-1])
            {
                vis[row][col-1]=1;
                q.push({row,col-1});
            }
            if (col+1<=m&&maze[row][col+1]!='#'&&!vis[row][col+1])
            {
                vis[row][col+1]=1;
                q.push({row,col+1});
            }
        }
        for (auto i:goodPos)
            if (!(posPlace[i.first][i.second]))
                bisa=0;
        if (bisa)
            cout<<"Yes\n";
        else cout<<"No\n";
    }
}