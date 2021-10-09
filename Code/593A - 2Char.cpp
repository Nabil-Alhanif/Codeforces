#include <bits/stdc++.h>
using namespace std;
typedef uint_fast64_t ll;
const ll MOD = 1e9+7, INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    map<char, int> lone_letter;
    map<pair<char, char>, int> double_letter;

    while (n--)
    {
        string s;
        cin >> s;

        char c1 = s[0], c2 = '0';
        for (auto i:s)
        {
            if (i != c1)
            {
                if (c2 == '0')
                    c2 = i;
                else if (i != c2)
                    c2 = '1';
            }
        }

        //cout << s << " " << c1 << " " << c2 << "\n";

        if (c2 == '1')
            continue;
        if (c2 == '0')
            lone_letter[c1] += s.size();
        else
        {
            double_letter[{c1, c2}] += s.size();
            double_letter[{c2, c1}] += s.size();
        }
    }

    ll ans = 0;
    for (char i = 'a'; i <= 'z'; i++)
    {
        ans = max(ans, (ll)(lone_letter[i]));

        for (char j = i + 1; j <= 'z'; j++)
            ans = max(ans, (ll)(lone_letter[i] + lone_letter[j] + double_letter[{i, j}]));
    }

    cout << ans << "\n";
}
