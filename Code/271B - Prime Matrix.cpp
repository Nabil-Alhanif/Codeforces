#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7, inf = 1e13;

bool notPrime[100005];
vector<ll> sieve()
{
    notPrime[0] = 1;
    notPrime[1] = 1;
    for (ll i=2; i*i<100005; i++)
    {
        if (!notPrime[i])
            for (ll j=i*i; j<100005; j+=i)
                notPrime[j] = 1;
    }
    vector<ll>ret;
    for (ll i=2; i<100005; i++)
        if (!notPrime[i])
            ret.push_back(i);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> mat(n, vector<ll>(m));
    vector<ll> jum(n+m);
    vector<ll> prime = sieve();
    for (ll i=0; i<n; i++)
    {
        for (ll j=0; j<m; j++)
        {
            cin >> mat[i][j];
            if (notPrime[mat[i][j]])
            {
                ll closestPrime = *upper_bound(prime.begin(), prime.end(), mat[i][j]);
                jum[i] += closestPrime - mat[i][j];
                jum[n+j] += closestPrime - mat[i][j];
            }
        }
    }
    ll ans = inf;
    for (auto i:jum)
        ans = min(ans, i);
    cout << ans << "\n";
}