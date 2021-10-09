#include <bits/stdc++.h>
using namespace std;
typedef uint_fast64_t ll;
const ll MOD = 1e9+7, INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<int> male(367), female(367);
    for (int i = 0; i < n; i++)
    {
        char gender; int first_day, last_day;
        cin >> gender >> first_day >> last_day;

        if (gender == 'M')
        {
            for (int j = first_day; j <= last_day; j++)
                male[j]++;
        }
        else
        {
            for (int j = first_day; j <= last_day; j++)
                female[j]++;
        }
    }

    int ans = 0;
    for (int i = 1; i <= 366; i++)
        ans = max(ans, min(male[i], female[i]) * 2);
    cout << ans << "\n";
}
