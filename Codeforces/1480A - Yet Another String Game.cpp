#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
ll INF = 1e18, MOD = 1e9+7;

template <class _tp> inline void operator+=(pair<_tp, _tp> &lh, const pair<_tp, _tp> &rh)
{
    lh.first += rh.first;
    lh.second += rh.second;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        
        int size = s.size();
        for (int i = 0; i < size; i++)
        {
            if (i%2)
            {
                if (s[i] != 'z')
                    s[i] = 'z';
                else s[i] = 'y';
            }
            else
            {
                if (s[i] != 'a')
                    s[i] = 'a';
                else s[i] = 'b';
            }
        }

        cout << s << "\n";
    }
}
