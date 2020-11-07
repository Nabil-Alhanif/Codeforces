#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        map<pair<int,int>,bool>m;
        string s;
        cin>>s;
        int x=0, y=0;
        unsigned long long ans=0;
        for (auto i:s)
        {
            int tmpX=x,tmpY=y;
            if (i=='N')
                y++;
            if (i=='S')
                y--;
            if (i=='W')
                x--;
            if (i=='E')
                x++;
            if (m[{tmpX+x,tmpY+y}])
                ans++;
            else
            {
                m[{tmpX+x,tmpY+y}]=1;
                ans+=5;
            }
        }
        cout<<ans<<"\n";
    }
}