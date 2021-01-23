#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    while (t--)
    {
        string s;
        cin>>s;
        int n=s.size(),ans=0;
        //cout<<"\n";
        for (int i=1;i<n;i++)
        {
            if (s[i]==s[i-1]&&s[i]!='.'&&s[i-1]!='.')
            {
                s[i]='.';
                ans++;
            }
            else
            {
                if (i>1)
                {
                    if (s[i-2]==s[i]&&s[i]!='.'&&s[i-2]!='.')
                    {
                        s[i]='.';
                        ans++;
                    }
                }
            }
            //cout<<s<<"\n";
        }
        cout<<ans<<"\n";
    }
}