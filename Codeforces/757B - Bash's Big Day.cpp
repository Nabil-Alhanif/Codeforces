#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9+7, INF = 1e18;
const double PI = acos(-1);

vector<vector<ll>> combinatoric(61, vector<ll>(61));

void count_combinatoric()
{
    // Base case
    for (int i = 0; i <= 60; i++)
        combinatoric[i][0] = 1;

    for (int i = 1; i <= 60; i++)
    {
        for (int j = 1; j <= 60; j++)
            combinatoric[i][j] = ((combinatoric[i-1][j-1]) + (combinatoric[i-1][j]));
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, tmp, ans = 1;
    cin >> n;

    map<int, int> cnt;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;

        if (!(tmp % 2))
            cnt[2]++;

        while (tmp % 2 == 0)
            tmp /= 2;

        for (int i = 3; i * i <= tmp; i += 2)
        {
            if (tmp % i == 0)
                cnt[i]++;

            while (tmp % i == 0)
                tmp /= i;
        }

        if (tmp > 2)
            cnt[tmp]++;
    }

    for (auto i:cnt)
        ans = max(ans, i.second);

    cout << ans << "\n";
}
