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
        int n;
        cin >> n;

        vector<ll> height(n);
        for (auto &i:height)
            cin >> i;

        sort(height.begin(), height.end());

        ll dif = INF, idx; // idx itu index kiri nya. Misal, 1 3 5 6, kan yang paling mirip itu 5 6, jadi idx itu index nya 5, yaitu 2.
        for (int i = 0; i < n-1; i++)
        {
            if ((height[i+1] - height[i]) < dif)
            {
                dif = (height[i+1] - height[i]);
                idx = i;
            }
        }

        if (n == 2)
        {
            cout << height[0] << " " << height[1] << "\n";
            continue;
        }

        cout << height[idx+1] << " ";
        for (int i = idx+2; i < n; i++)
            cout << height[i] << " ";
        for (int i = 0; i < idx; i++)
            cout << height[i] << " ";
        cout << height[idx] << "\n";
    }
}
