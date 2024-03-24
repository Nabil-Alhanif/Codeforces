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
        string s, t, p;
        cin >> s >> t >> p;

        map<char, int> cnt;
        for (auto i:p)
            cnt[i]++;

        int s_index = 0;
        int size = s.size();

        s = s + '0';
        
        bool bisa = 1;
        for (auto i:t)
        {
            if (i != s[s_index])
            {
                // If it is not the same with s, then take a char from p and insert it there.
                if (cnt[i] == 0)
                {
                    bisa = 0;
                    break;
                }
                cnt[i]--;
            }
            else s_index++;
        }

        if (s_index != size)
            bisa = 0;

        cout << (bisa ? "Yes\n" : "No\n");
    }
}
