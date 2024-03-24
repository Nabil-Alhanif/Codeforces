#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n,x,odd=0,even=0;
        cin>>n>>x;
        while (n--)
        {
            int tmp;
            cin>>tmp;
            if (tmp%2)
                odd++;
            else
                even++;
        }
        n=odd+even;
        if (!odd)
        {
            cout<<"NO\n";
            continue;
        }
        if (even>=x)
            cout<<"YES\n";
        else 
        {
            if (even)
            {
                x-=even;
                if (odd>x)
                    cout<<"YES\n";
                else
                {
                    if (x%2)
                        cout<<"YES\n";
                    else
                        cout<<"NO\n";
                }
            }
            else
            {
                if (x%2)
                    cout<<"YES\n";
                else
                    cout<<"NO\n";
            }
        }
    }
}