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
        ll n, k;
        cin >> n >> k;

        vector<ll> mountain(n+1), peak(n+1);
        for (int i = 1; i <= n; i++)
            cin >> mountain[i];

        for (int i = 2; i < n; i++)
        {
            peak[i] = peak[i-1];
            if ((mountain[i] > mountain[i-1]) && (mountain[i] > mountain[i+1]))
                peak[i] += 1;
        }

        peak[n] = peak[n-1];

        int left_bound, right_bound; // Jelas lah ya, batas kiri sama kanan
        ll ans = 0, left_ans = 1, tmp; // left_ans itu batas kiri terkecil nya
        for (int i = k; i <= n; i++)
        {
            left_bound = i - k + 1;
            right_bound = i;

            tmp = peak[right_bound - 1] - peak[left_bound]; // Ini prefix sum

            if (tmp > ans)
            {
                ans = tmp;
                left_ans = left_bound;
            }
        }

        cout << ans+1 << " " << left_ans << "\n";
    }
}
