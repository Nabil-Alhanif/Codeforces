#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 10007, INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int k, n, m;
        cin >> k >> n >> m;

        vector<int> monocarp(n+1, INT_MAX), polycarp(m+1, INT_MAX), ans(n+m);

        for (int i = 0; i < n; i++)
            cin >> monocarp[i];

        for (int i = 0; i < m; i++)
            cin >> polycarp[i];

        int mono = 0, poly = 0;
        bool bisa = 1;

        for (int i = 0; i < n + m; i++)
        {
            if (monocarp[mono] <= k)
            {
                if (monocarp[mono] == 0)
                    k++;
                ans[i] = monocarp[mono];
                mono++;
            }
            else if (polycarp[poly] <= k)
            {
                if (polycarp[poly] == 0)
                    k++;
                ans[i] = polycarp[poly];
                poly++;
            }
            else
            {
                bisa = 0;
                break;
            }
        }

        if (bisa)
        {
            for (auto i:ans)
                cout << i << " ";
            cout << "\n";
        }
        else cout << "-1\n";
    }
}
