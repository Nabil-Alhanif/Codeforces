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
        int n, biggest_fish = 0;
        cin >> n;

        vector<int> piranhas(n);
        for (auto &piranha:piranhas)
        {
            cin >> piranha;
            biggest_fish = max(biggest_fish, piranha);
        }

        bool there_is_always_a_bigger_fish = 1;

        for (int i = 0; i < n && there_is_always_a_bigger_fish; i++)
        {
            if (piranhas[i] == biggest_fish)
            {
                if (i-1 >= 0)
                {
                    if (piranhas[i-1] < biggest_fish)
                    {
                        cout << i+1 << "\n";
                        there_is_always_a_bigger_fish = 0;
                        break;
                    }
                }
                if (i+1 < n)
                {
                    if (piranhas[i+1] < biggest_fish)
                    {
                        cout << i+1 << "\n";
                        there_is_always_a_bigger_fish = 0;
                        break;
                    }
                }
            }
        }
        
        if (there_is_always_a_bigger_fish)
            cout << "-1\n";
    }
}
