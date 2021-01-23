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
        ll n,bob=0,alice=0;
        cin>>n;
        priority_queue<ll> odd,even;
        for (int i=0;i<n;i++)
        {
            ll tmp;
            cin>>tmp;
            if (tmp%2)
                odd.push(tmp);
            else even.push(tmp);
        }
        for (int i=0;i<n;i++)
        {
            if (i%2)
            {
                if (!odd.empty()&&!even.empty())
                {
                    if (odd.top()>=even.top())
                    {
                        bob+=odd.top();
                        odd.pop();
                    }
                    else even.pop();
                }
                else if (!odd.empty()&&even.empty())
                {
                    bob+=odd.top();
                    odd.pop();
                }
                else even.pop();
            }
            else
            {
                if (!odd.empty()&&!even.empty())
                {
                    if (even.top()>=odd.top())
                    {
                        alice+=even.top();
                        even.pop();
                    }
                    else odd.pop();
                }
                else if (!odd.empty()&&even.empty())
                    odd.pop();
                else
                {
                    alice+=even.top();
                    even.pop();
                }
            }
            if (alice==bob)
            {
                alice=0;
                bob=0;
            }
            else if (alice>bob)
            {
                alice-=bob;
                bob=0;
            }
            else
            {
                bob-=alice;
                alice=0;
            }
        }
        if (bob>alice)
            cout<<"Bob\n";
        else if (bob<alice)
            cout<<"Alice\n";
        else cout<<"Tie\n";
    }
}