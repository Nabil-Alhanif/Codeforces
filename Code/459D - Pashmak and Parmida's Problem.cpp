#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e13, MAXN=1e6+5;
map<ll, ll> depan, belakang;
ll suff[MAXN], tree[MAXN], ar[MAXN], ans, n;

void update(ll i)
{
    for (i; i<=n; i+=i&(-i))
        tree[i]++;
}

ll query(ll i)
{
    ll ret = 0;
    for (i; i>0; i-=i&(-i))
        ret += tree[i];
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> ar[i];
    for (int i=1; i<=n; i++)
    {
        depan[ar[i]]++;
        suff[i] = depan[ar[i]];
    }
    for (int i=n; i>0; i--)
    {
        belakang[ar[i]]++;
        ans += query(suff[i]-1);
        update(belakang[ar[i]]);
    }
    cout << ans << "\n";
}