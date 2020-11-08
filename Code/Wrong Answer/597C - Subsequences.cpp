#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int ar[200005],pref[200005];
void preSum(int n)
{
    for (int i=1;i<=n;i++)
    {
        int b=i+(i&-i);
        if (b<=n)
            pref[b]+=pref[i];
    }
}

void printPresum(int n)
{
    for (int i=1;i<=n;i++)
        cout<<pref[i]<<" ";
    cout<<"\n";
}

void add(int i,int x,int n)
{
    ar[i]+=x;
    while (i<=n)
    {
        pref[i]+=x;
        i+=(i&-i);
    }
}

int sum(int n)
{
    int ret=0;
    while (n)
    {
        ret+=pref[n];
        n-=(n&-n);
    }
    return ret;
}

int main()
{
    int n,k;ll ans=0;
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        cin>>ar[i];
        pref[i]=ar[i];
    }
    preSum(n);
    printPresum(n);
    for (int i=1;i<=n;i++)
        cout<<i<<" "<<sum(i)<<"\n";
}