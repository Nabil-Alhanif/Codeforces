#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        string s;
        cin>>s;
        int one=0,zero=0;
        for (auto i:s)
            if (i=='1')
                one++;
            else zero++;
        if (min(one,zero)%2)
            cout<<"DA\n";
        else cout<<"NET\n";
    }
}