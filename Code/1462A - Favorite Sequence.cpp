#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        ll ar[n];
        for (int i=0;i<n;i++)
            cin>>ar[i];
        int i=0,j=n-1;
        while (i<=j)
        {
            if (i!=j)
                cout<<" "<<ar[i]<<" "<<ar[j];
            else cout<<" "<<ar[i];
            i++;
            j--;
        }
        cout<<"\n";
    }
}