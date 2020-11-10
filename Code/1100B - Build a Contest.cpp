#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,tot=0;
    cin>>n>>m;
    map<int,int>pool;
    while (m--)
    {
        int diff;
        cin>>diff;
        if (pool[diff]==0)
            tot++;
        pool[diff]++;
        if (tot==n)
        {
            cout<<1;
            for (int i=1;i<=n;i++)
            {
                if (pool[i]==1)
                    tot--;
                pool[i]--;
            }
        }
        else
            cout<<0;
    }
    cout<<"\n";
}