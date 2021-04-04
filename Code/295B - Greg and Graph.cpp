#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin>>n;
    vector<vector<ll>>adjMat(n,vector<ll>(n));
    vector<bool>notGone(n);
    vector<ll>ans(n),del(n);
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            cin>>adjMat[i][j];
    //cout<<"Graph\n";
    for (int i=0;i<n;i++)
    {
        cin>>del[i];
        del[i]--;
    }
    //cout<<"Del\n";
    for (int i=n-1;i>=0;i--)
    {
        notGone[del[i]]=1;
        for (int j=0;j<n;j++)
        {
            for (int k=0;k<n;k++)
            {
                //cout<<i<<" "<<j<<" "<<k<<"\n";
                adjMat[j][k]=min(adjMat[j][k],adjMat[j][del[i]]+adjMat[del[i]][k]);
                if (notGone[j]&&notGone[k])
                    ans[i]+=adjMat[j][k];
            }
        }
    }
    for (int i=0;i<n;i++)
        cout<<ans[i]<<" ";
    cout<<"\n";
}