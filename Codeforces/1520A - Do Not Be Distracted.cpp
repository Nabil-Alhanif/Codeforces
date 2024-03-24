#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
ll INF = 1e18, MOD = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        
        bool susp = 0;
        map<char, int> sus;
        
        sus[s[0]]++;
        for (int i = 1; i < n; i++)
        {
            if (s[i] != s[i-1])
            {
                if (sus[s[i]])
                {
                    susp = 1;
                    break;
                }
                sus[s[i]]++;
            }
        }

        cout << (susp?"NO\n":"YES\n");
    }
}
