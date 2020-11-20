#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n,m,x,y,ans=0,tmp=0;
        cin>>n>>m>>x>>y;
        y=min(y,2*x);
        //cout<<"Y: "<<y<<"\n";
        vector<vector<char>>theatre(n,vector<char>(m));
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                cin>>theatre[i][j];
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                if (theatre[i][j]=='.')
                {
                    if (j+1<m)
                    {
                        if (theatre[i][j+1]=='.')
                        {
                            ans+=y;
                            theatre[i][j]='*';
                            theatre[i][j+1]='*';
                            continue;
                        }
                    }
                    ans+=x;
                    theatre[i][j]='*';
                    /*
                    cout<<++tmp<<" Move.\n";
                    for (int k=0;k<m;k++)
                    {
                        for (int l=0;l<n;l++)
                            cout<<theatre[k][l];
                        cout<<"\n";
                    }
                    cout<<"Current cost: "<<ans<<".\n";
                    */
                }
            }
        }
        cout<<ans<<"\n";
    }
}