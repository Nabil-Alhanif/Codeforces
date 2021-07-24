#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 10007, INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        string s, s2 = "a";
        cin >> s;

        vector<int> hash(26, -1);
        bool bisa = 1;
        int size = s.size();
        
        for (auto &i:s)
        {
            if (hash[i-'a'] != -1)
            {
                bisa = 0;
                break;
            }
            
            hash[i-'a'] = ((&i) - (&s[0]));
        }

        for (int i = 0; (i < size) && bisa; i++)
        {
            if (hash[i] == -1)
            {
                bisa = 0;
                break;
            }

            if (i > 0)
            {
                if (hash[i] > hash[i-1])
                    s2 = s2 + (char)(i + 'a');
                else
                    s2 = (char)(i + 'a') + s2;
            }
        }

        bisa &= (s2 == s);
        cout << (bisa ? "Yes\n" : "No\n");
    }
}
