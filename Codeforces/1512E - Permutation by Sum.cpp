#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9 + 7, INF = 1e18;
const double PI = acos(-1);

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t, n, l, r, s, k;
    cin >> t;

    while (t--)
    {
        cin >> n >> l >> r >> s;
        k = r - l + 1;

        if (((k * (k + 1)) / 2 > s) || ((k * (2 * n + 1 - k)) / 2 < s))
        {
            cout << "-1\n";
            continue;
        }

        vector<int> ans;
        map<int, bool> m;

        for (int i = n ; i > 0; i--)
        {
            if (s - i >= (((k - 1) * k ) / 2))
            {
                ans.push_back(i);
                m[i] = 1;
                s -= i;
                k--;
            }
        }

        for (int i = 1, cnt = 1; cnt < l; i++)
        {
            if (!m[i])
            {
                m[i] = 1;
                cnt++;
                cout << i << " ";
            }
        }

        for (auto i:ans)
            cout << i << " ";

        for (int i = 1, cnt = r + 1; cnt <= n; i++)
        {
            if (!m[i])
            {
                cnt++;
                cout << i << " ";
            }
        }

        cout << "\n";
    }
}
