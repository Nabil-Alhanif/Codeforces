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
        string s;
        cin >> s;

        vector<int> ans;
        int size = s.size();

        // twone
        for (int i = 0; i < size-4; i++)
        {
            if (((s[i] == 't') && (s[i+1] == 'w')) && (((s[i+2] == 'o') && ((s[i+3] == 'n' && s[i+4] == 'e')))))
            {
                ans.push_back(i+2);
                s[i+2] = '0';
            }
        }

        // two
        for (int i = 0; i < size-2; i++)
        {
            if ((s[i] == 't') && ((s[i+1] == 'w') && s[i+2] == 'o'))
            {
                ans.push_back(i+1);
                s[i+1] = '0';
            }
        }
        
        // one
        for (int i = 0; i < size-2; i++)
        {
            if ((s[i] == 'o') && ((s[i+1] == 'n') && s[i+2] == 'e'))
            {
                ans.push_back(i+1);
                s[i+1] = '0';
            }
        }

        cout << ans.size() << "\n";
        for (auto i:ans)
            cout << i+1 << " ";
        cout << "\n";
    }
}

