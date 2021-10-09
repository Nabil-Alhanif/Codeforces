#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9 + 7, INF = 1e18;
const double PI = acos(-1);

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, cnt, ans = 0, lim = 1e6 + 1e3;
    cin >> n;

    vector<int> pow(lim);
    for (int i = 0; i < n; i++)
    {
        cin >> cnt;
        pow[cnt]++;
    }

    for (int i = 0; i < lim; i++)
    {
        pow[i + 1] += (pow[i] / 2);
        pow[i] %= 2;

        ans += pow[i];
    }

    cout << ans << "\n";
}
