#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9 + 7, INF = 1e18;
const double PI = acos(-1);

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s;
    cin >> s;

    int n = s.size(), ans = 0;

    vector<int> prefa(n + 1), prefb(n + 1);

    if (s[0] == 'a')
        prefa[1]++;
    else prefb[1]++;

    for (int i = 2; i <= n; i++)
    {
        prefa[i] = prefa[i - 1];
        prefb[i] = prefb[i - 1];

        if (s[i - 1] == 'a')
            prefa[i]++;
        else prefb[i]++;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i - 1; j <= n; j++)
            ans = max(ans, prefa[i - 1] + (prefb[j] - prefb[i - 1]) + (prefa[n] - prefa[j]));
    }

    cout << ans << "\n";
}
