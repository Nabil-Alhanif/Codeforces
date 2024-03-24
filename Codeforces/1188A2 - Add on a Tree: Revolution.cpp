#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll E=1e3+5;
ll n, u[E], v[E], val[E], d[E];
 
vector<ll>V[E], ans;
 
int leave (int parent, int now)
{
    if (d[now]==1)
    {
        return now;
    }
    for (int i=0; i<V[now].size(); i++)
    {
        if (V[now][i]!=parent)
        {
            return leave(now,V[now][i]);
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    scanf("%lld", &n);
    for (int q=0; q<n-1; q++)
    {
        scanf("%lld%lld%lld", &u[q], &v[q], &val[q]);
        V[u[q]].push_back(v[q]);
        V[v[q]].push_back(u[q]);
        d[u[q]]++;
        d[v[q]]++;
    }
    for (int q=1; q<=n; q++)
    {
        if (d[q]==2)
        {
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
    for (int q=0; q<n-1; q++)
    {
        int a=0, b=0, c=0, d=0;
        if  (V[v[q]].size()==1)
        {
            a=v[q];
            b=a;
        }
        else
        {
            for  (int i=0;  i<V[v[q]].size();  i++)
            {
                if  (V[v[q]][i]  !=  u[q])
                {
                    if (a == 0)
                    {
                        a = leave (v[q] , V[v[q]][i]);
                    }
                    else
                    {
                        b = leave (v[q] , V[v[q]][i]);
                        break;
                    }
                }
            }
        }
        if  (V[u[q]].size()==1)
        {
            c=u[q];
            d=c;
        }
        else
        {
            for  (int i=0;  i<V[u[q]].size();  i++)
            {
                if  (V[u[q]][i]  !=  v[q])
                {
                    if (c == 0)
                    {
                        c = leave (u[q] , V[u[q]][i]);
                    }
                    else
                    {
                        d = leave (u[q] , V[u[q]][i]);
                        break;
                    }
                }
            }
        }
        if (a == b&&c == d)
        {
            ans.push_back(a);
            ans.push_back(c);
            ans.push_back(val[q]);
            // cout<<a<<' '<<c<<" "<<val[q]<<'\n';
        }
        else if (c==d)
        {
            ans.push_back(a);
            ans.push_back(u[q]);
            ans.push_back(val[q]/2);
            
            ans.push_back(b);
            ans.push_back(u[q]);
            ans.push_back(val[q]/2);
            
            ans.push_back(a);
            ans.push_back(b);
            ans.push_back(-val[q]/2);
            
            // cout<<a<<' '<<u[q]<<' '<<val[q]/2<<'\n';
            // cout<<b<<' '<<u[q]<<' '<<val[q]/2<<'\n';
            // cout<<a<<' '<<b<<' '<<-val[q]/2<<'\n';
        }
        else if (a==b)
        {
            ans.push_back(c);
            ans.push_back(v[q]);
            ans.push_back(val[q]/2);
            ans.push_back(d);
            ans.push_back(v[q]);
            ans.push_back(val[q]/2);
            ans.push_back(c);
            ans.push_back(d);
            ans.push_back(-val[q]/2);
        }
        else
        {
            ans.push_back(a);
            ans.push_back(c);
            ans.push_back(val[q]/2);
            ans.push_back(b);
            ans.push_back(d);
            ans.push_back(val[q]/2);
            ans.push_back(a);
            ans.push_back(b);
            ans.push_back(-val[q]/2);
            ans.push_back(c);
            ans.push_back(d);
            ans.push_back(-val[q]/2);
        }
    }
    cout << ans.size()/3 << '\n';
    for (int i=0; i<ans.size(); i++)
    {
        cout<<ans[i];
        if (i%3==2)
        {
          cout<<'\n';
        }
        else
        {
          cout<<' ';
        }
    }
}
 
// a   c
//  u v
// b   d
 
// a c +x/2
// b d +x/2
// a b -x/2
// c d -x/2
 
// a
//  u v
// b
 
// a v +x/2
// b v +x/2
// a b -x/2
