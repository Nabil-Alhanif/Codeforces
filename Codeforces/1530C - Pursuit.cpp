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
        int n, ans = 0;
        cin >> n;

        vector<ll> you(n+1), ilya(n+1);
        for (int i = 1; i <= n; i++)
            cin >> you[i];
        sort(you.begin(), you.end());
 
        for (int i = 1; i <= n; i++)
            cin >> ilya[i];
        sort(ilya.begin(), ilya.end());

        for (int i = 1; i <= n; i++)
        {
            you[i] += you[i-1];
            ilya[i] += ilya[i-1];
        }

        int you_score = you[n] - you[n/4];
        int ilya_score = ilya[n] - ilya[n/4];

        if (you_score >= ilya_score)
        {
            cout << ans << "\n";
            continue;
        }

        int l = 1, r = 1e5, mid;
        while (l <= r)
        {
            mid = (l + r) / 2;
            int total_stage = mid + n;
            int reduced = total_stage / 4;

            if (reduced >= n)
                you_score = 100 * (mid - (reduced - n));
            else you_score = (100 * mid) + (you[n] - you[reduced]);

            if (reduced <= mid)
                ilya_score = ilya[n];
            else ilya_score = ilya[n] - ilya[reduced - mid];

            // cout << mid << " " << you_score << " " << ilya_score << "\n";

            if (you_score >= ilya_score)
            {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }

        cout << ans << "\n";
    }
}
