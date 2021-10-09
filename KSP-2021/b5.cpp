#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9 + 7, INF = 1e18;
const double PI = acos(-1);

// Bad Practice? Yeah, but IDC for now
int n, m, a, b, q, gcdd, tmp, pos, ta, tb;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> a >> b >> q;

    vector<pair<double, pair<int, int>>> suhu(n * m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            pos = ((m * i) - m + j - 1);
            ta = a + i;
            tb = b + j;
            gcdd = __gcd(ta, tb);

            suhu[pos] = {((double)tb) / ((double)ta), {(tb / gcdd), (ta / gcdd)}};
        }
    }
    sort(suhu.begin(), suhu.end());

    while (q--)
    {
        cin >> tmp;
        cout << suhu[tmp - 1].second.first << "/" << suhu[tmp - 1].second.second << "\n";
    }
}
