#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e12, MOD = 1e9+7;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll p, a, b, c;
        cin >> p >> a >> b >> c;
        ll ta = (a-(p%a))%a;
        ll tb = (b-(p%b))%b;
        ll tc = (c-(p%c))%c;
        cout << min(ta, min(tb, tc)) << "\n";
    }
}
