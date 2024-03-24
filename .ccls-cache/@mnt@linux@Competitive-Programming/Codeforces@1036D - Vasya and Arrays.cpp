#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9 + 7, INF = 1e18;
const double PI = acos(-1);

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, m, tmpa = 0, tmpb = 0, tota = 0, totb = 0, posa = 0, posb = 0, ans = 0;

    cin >> n;
    vector<ll> ar(n);

    for (auto &i:ar)
    {
        cin >> i;
        tmpa += i;
    }

    tota = ar[0];

    cin >> m;
    vector<ll> br(m);

    for (auto &i:br)
    {
        cin >> i;
        tmpb += i;
    }

    totb = br[0];

    if (tmpa != tmpb)
        return cout << "-1\n", 0;

    while ((posa < n) && (posb < m))
    {
        if (tota == totb)
        {
            ans++;

            posa++;
            posb++;
            if ((posa == n) || (posb == m))
                break;

            tota = ar[posa];
            totb = br[posb];
        }
        else if (tota < totb)
        {
            posa++;
            tota += ar[posa];
        }
        else
        {
            posb++;
            totb += br[posb];
        }
    }
    cout << ans << "\n";
}
