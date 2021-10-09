#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9+7, INF = 1e18;
const double PI = acos(-1);

vector<vector<ll>> combinatoric(61, vector<ll>(61));

void count_combinatoric()
{
    // Base case
    for (int i = 0; i <= 60; i++)
        combinatoric[i][0] = 1;

    for (int i = 1; i <= 60; i++)
    {
        for (int j = 1; j <= 60; j++)
            combinatoric[i][j] = ((combinatoric[i-1][j-1]) + (combinatoric[i-1][j]));
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, tmp, k1, k2;
    cin >> n >> k1;

    queue<int> s1, s2; // Soldier 1, 2
    map<pair<int, int>, bool> loop; // To check if there are loop

    for (int i = 0; i < k1; i++)
    {
        cin >> tmp;
        s1.push(tmp);
    }

    cin >> k2;
    for (int i = 0; i < k2; i++)
    {
        cin >> tmp;
        s2.push(tmp);
    }

    bool game = 1;
    int loop_size = 0;
    while (game)
    {
        loop_size++;
        k1 = s1.front();
        k2 = s2.front();
        s1.pop();
        s2.pop();

        //cout << loop_size << " " << k1 << " " << k2 << "\n";

        if (k1 == k2)
        {
            s1.push(k1);
            s2.push(k2);
        }
        else if (k1 > k2)
        {
            s1.push(k2);
            s1.push(k1);
        }
        else
        {
            s2.push(k1);
            s2.push(k2);
        }

        if (s1.empty() || s2.empty())
            break;

        if (loop_size >= 1e6)
        {
            game = 0;
            break;
        }
    }

    if (!game)
        cout << "-1\n";
    else
    {
        if (s1.empty())
            cout << loop_size << " 2\n";
        else cout << loop_size << " 1\n";
    }
}
