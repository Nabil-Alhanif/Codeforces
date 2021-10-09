#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9 + 7, INF = 1e18;
const double PI = acos(-1);

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, l, r, maks = 0;
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
        else
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
    }

    cout << ans.size() << "\n";
    for (auto i:ans)
        cout << i;
    cout << "\n";
}
