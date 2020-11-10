#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n,m,k,pPok=0;
        cin>>n>>m>>k;
        pPok=min(n/k,m);
        m-=pPok;
        int enPok=(m/(k-1))+(m%(k-1)?1:0);
        cout<<pPok-enPok<<"\n";
    }
}