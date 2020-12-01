#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
string s;
struct Node{
    int a,b,c;
    Node()
    {
        a=0,b=0,c=0;
    }
};
Node t[MAXN*4];
Node merge(Node a, Node b)
{
    int t=min(a.b,b.c);
    Node ret;
    ret.a=a.a+b.a+t*2;
    ret.b=a.b+b.b-t;
    ret.c=a.c+b.c-t;
    return ret;
}
void build(int v, int tl, int tr)
{
    if (tl==tr)
    {
        if (s[tl]=='(')
            t[v].b=1;
        else
            t[v].c=1;
        return;
    }
    else
    {
        int tm = (tl + tr) / 2;
        build(v*2,tl,tm);
        build(v*2+1,tm+1,tr);
        t[v]=merge(t[v*2],t[v*2+1]);
    }
}
Node count(int v, int tl, int tr, int l, int r)
{
    if (tl==l&&tr==r)
        return t[v];
    int tm=(tl+tr)/2;
    if (r<=tm)
        return count(v*2,tl,tm,l,r);
    else if (l>tm)
        return count(v*2+1,tm+1,tr,l,r);
    else
        return merge(count(v*2,tl,tm,l,tm),count(v*2+1,tm+1,tr,tm+1,r));
}
int main()
{
    int size,q;
    cin>>s>>q;
    size=s.size();
    build(1,0,size-1);
    while (q--)
    {
        int l,r;
        cin>>l>>r;
        l--;r--;
        int ans=count(1,0,size-1,l,r).a;
        cout<<ans<<"\n";
    }
}