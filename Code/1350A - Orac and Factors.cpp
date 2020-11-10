#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n,k;
        cin>>n>>k;
        int m=2;
        while (n%m)
            m++;
        cout<<n+m+2*(k-1)<<"\n";
    }
}