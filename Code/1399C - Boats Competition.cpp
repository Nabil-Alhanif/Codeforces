#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
ll INF = 1e18, MOD = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, ans = 0;
        cin >> n;

        vector<int> weight(n, 0);
        map<int, int> data;
        for (auto &i:weight)
        {
            cin >> i;
            data[i]++;
        }

        vector<int> dp(n*2+1, 0); // Check for all possible weight;
        for (int i = 2; i <= n*2; i++) // i is from 2 because minimum weight per person is 1
        {
            map<int, int> tmp = data;
            
            for (auto &j:tmp)
            {
                int first_weight = j.first;
                int &first_amount = j.second;

                if (first_weight >= i)
                    continue;

                int second_weight = i-j.first;
                int &second_amount = tmp[second_weight];

                /*
                //DEBUG
                cout << first_weight << " " << first_amount << " first\n";
                cout << second_weight << " " << second_amount << " second\n";
                */

                int team_form;
                if (first_weight == second_weight)
                    team_form = first_amount / 2; // Or second_amount / 2, they're the same
                else team_form = min(first_amount, second_amount);

                first_amount -= team_form;
                second_amount -= team_form;
                dp[i] += team_form;

                //cout << team_form << " " << first_amount << " " << second_amount << "\n\n";
            }
            ans = max(ans, dp[i]);
        }
        cout << ans << "\n";
    }
}
