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
        pair<int, int> cur_pos, target;
        cin >> target.first >> target.second;

        string orders;
        cin >> orders;

        int up = 0, down = 0, left = 0, right = 0;
        
        for (auto order:orders)
        {
            if (order == 'U')
                up++;
            else if (order == 'D')
                down++;
            else if (order == 'L')
                left++;
            else right++;
        }

        bool bisa = 1;

        if (target.first > 0)
            bisa &= (bool)(right >= target.first);
        else if (target.first < 0)
            bisa &= (bool)(left >= abs(target.first));

        if (target.second > 0)
            bisa &= (bool)(up >= target.second);
        else if (target.second < 0)
            bisa &= (bool)(down >= abs(target.second));

        cout << (bisa?"YES\n":"NO\n");
    }
}
