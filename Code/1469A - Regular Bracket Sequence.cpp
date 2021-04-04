#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int m;
    cin>>m;
    while (m--)
    {
        bool bisa=1;
        string s;
        cin>>s;
        if (s.size()%2)
        {
            cout<<"NO\n";
            continue;
        }
        int size=s.size();
        int cl=0,op=0;
        for (int i=0;i<size;i++)
        {
            if (s[i]=='(')
                op++;
            else if (s[i]==')')
                cl++;
        }
        if (cl>size/2||op>size/2)
        {
            cout<<"NO\n";
            continue;
        }
        op=0,cl=0;
        int tt=0;
        for (int i=0;i<size;i++)
        {
            if (s[i]=='(')
                op++;
            else if (s[i]==')')
                cl++;
            else tt++;
            if (cl>0)
            {
                if (tt>0)
                {
                    tt--;
                    cl--;
                }
                else
                {
                    if (op>0)
                    {
                        op--;
                        cl--;
                    }
                    else
                    {
                        bisa=0;
                        break;
                    }
                }
            }
        }
        op=0,cl=0,tt=0;
        for (int i=size-1;i>=0;i--)
        {
            if (s[i]=='(')
                op++;
            else if (s[i]==')')
                cl++;
            else tt++;
            if (op>0)
            {
                if (tt>0)
                {
                    tt--;
                    op--;
                }
                else
                {
                    if (cl>0)
                    {
                        cl--;
                        op--;
                    }
                    else
                    {
                        bisa=0;
                        break;
                    }
                }
            }
        }
        if (bisa)
            cout<<"YES\n";
        else cout<<"NO\n";
    }
}