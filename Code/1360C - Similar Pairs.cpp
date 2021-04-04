#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while (n--)
    {
        int t,mt=0;
        cin>>t;
        int ar[t];
        for (int i=0;i<t;i++)
        {
            cin>>ar[i];
            if (ar[i]%2)
                mt++;
        }
        if (t>2)
        {

            int tm=t-mt;
            if (!(mt%2)&&!(tm%2))
                cout<<"YES\n";
            else
            {
                sort(ar,ar+t);
                bool b=0;
                for (int i=1;i<t;i++)
                    if (ar[i]==ar[i-1]+1)
                        b=1;
                cout<<(b?"YES\n":"NO\n");
            }
            continue;
        }
        sort(ar,ar+t);
        if (ar[0]+1==ar[1]||ar[0]%2==ar[1]%2)
            cout<<"YEs\n";
        else
            cout<<"NO\n";
    }
}