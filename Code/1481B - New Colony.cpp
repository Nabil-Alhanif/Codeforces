#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9+7, INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n, k, total = 0;
        cin >> n >> k;

        vector<int> height(n);
        map<int, int> m;
        for (auto &i:height)
        {
            cin >> i;
            total += i;
        }

        if ((k > 50000) || (n == 1))
        {
            cout << "-1\n";
            continue;
        }

        m[k] = -1;

        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < n-1; j++)
            {
                if (height[j] < height[j+1])
                {
                    //cout << i << " " << j << "\n";
                    height[j]++;
                    m[i+1] = j + 1;
                    break;
                }
            }
        }

        cout << m[k] << "\n";
    }
}
