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
        int people;
        cin >> people;

        vector<int> hero(101, 0);
        
        for (int i = 0; i < people; i++)
        {
            int power;
            cin >> power;
            hero[power]++;
        }

        for (auto i:hero)
        {
            if (i)
            {
                cout << people - i << "\n";
                break;
            }
        }
    }
}
