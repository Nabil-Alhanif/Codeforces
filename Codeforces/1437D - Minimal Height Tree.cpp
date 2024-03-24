#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9 + 7, INF = 1e18;
const double PI = acos(-1);

inline void sieve(vector<bool> &vect, int lim = 1e6)
{
    vect[0] = 1;
    vect[1] = 1;

    for (int i = 2; i * i <= lim; i++)
    {
        for (int j = i * i; j <= lim; j += i)
            vect[j] = 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int t, n, tmp;
    cin >> t;

    while (t--)
    {
        cin >> n;

        vector<int> bfs(n);
        for (auto &i:bfs)
            cin >> i;

        vector<int> cnt;
        cnt.push_back(1);

        tmp = 1;
        for (int i = 2; i < n; i++)
        {
            if (bfs[i] < bfs[i - 1])
            {
                cnt.push_back(tmp);
                tmp = 0;
            }

            tmp++;
        }
        cnt.push_back(tmp);

        int size = cnt.size();
        vector<int> dp(size);
        dp[0] = 1;

        for (int i = 1; i < size; i++)
            dp[i] = dp[i - 1] + cnt[i];

        /*
        for (int i = 0; i < size; i++)
            cout << "i: " << i << " cnt: " << cnt[i] << " dp: " << dp[i] << "\n";
        */

        int left = 0, right = 1, count = 1, ans = 0;
        while (count < n)
        {
            //cout << "count: " << count << " left: " << left << " right: " << right << "\n";
            ans++;
            if (right >= size)
                break;

            count += (dp[right] - dp[left]);
            left = right;
            right = count;
        }

        cout << ans << "\n";
    }
}
