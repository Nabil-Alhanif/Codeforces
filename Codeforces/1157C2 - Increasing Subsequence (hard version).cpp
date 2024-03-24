#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9 + 7, INF = 1e18;
const double PI = acos(-1);

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, l, r, maks = 0, cntl = 0, cntr = 0, tmp;
    cin >> n;

    vector<int> ar(n);
    vector<char> ans;

    for (auto &i:ar)
        cin >> i;

    l = 0, r = n - 1;
    while (1)
    {
        if (l > r)
            break;

        if (ar[l] < ar[r])
        {
            if (ar[l] > maks)
            {
                maks = ar[l];
                ans.push_back('L');
                l++;
            }
            else if (ar[r] > maks)
            {
                maks = ar[r];
                ans.push_back('R');
                r--;
            }
            else break;
        }
        else if (ar[r] < ar[l])
        {
            if (ar[r] > maks)
            {
                maks = ar[r];
                ans.push_back('R');
                r--;
            }
            else if (ar[l] > maks)
            {
                maks = ar[l];
                ans.push_back('L');
                l++;
            }
            else break;
        }
        else
        {
            tmp = maks;
            for (int i = l; i <= r; i++)
            {
                if (ar[i] > tmp)
                {
                    cntl++;
                    tmp = ar[i];
                }
                else break;
            }

            tmp = maks;
            for (int i = r; i >= l; i--)
            {
                if (ar[i] > tmp)
                {
                    cntr++;
                    tmp = ar[i];
                }
                else break;
            }

            if (cntl > cntr)
            {
                while (cntl--)
                    ans.push_back('L');
            }
            else
            {
                while (cntr--)
                    ans.push_back('R');
            }

            break;
        }
    }

    cout << ans.size() << "\n";
    for (auto i:ans)
        cout << i;
    cout << "\n";
}
