#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie();cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int n,m;
        cin>>n>>m;
        vector<bool>col(n),row(m);
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                int tmp;
                cin>>tmp;
                if (tmp)    
                {
                    //cout<<i<<" "<<j<<" id\n";
                    col[i]=1;
                    row[j]=1;
                }
            }
        }
        int colCount=n,rowCount=m;
        for (auto i:col)
            colCount-=i;
        for (auto i:row)
            rowCount-=i;
        //cout<<colCount<<" "<<rowCount<<"\n";
        if (!(min(rowCount,colCount)%2))
            cout<<"Vivek\n";
        else cout<<"Ashish\n";       
    }
}