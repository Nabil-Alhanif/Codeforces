#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9+7, INF = 1e18;
const double PI = acos(-1);

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll q, k, n, a, b, left, right, mid, ans;
    cin >> q;

    while (q--)
    {
        cin >> k >> n >> a >> b;

        if (k <= (n * b))
        {
            cout << "-1\n";
            continue;
        }

        left = 0, right = n, ans = 0;
        while (left <= right)
        {
            // Mid itu jumlah dia main doang tanpa nge cas
            mid = (left + right) / 2;

            if ((mid * a) + ((n - mid) * b) < k) // Artinya bisa
            {
                ans = mid;
                left = mid + 1;
            }
            else right = mid - 1;
        }

        cout << ans << "\n";
    }
}
