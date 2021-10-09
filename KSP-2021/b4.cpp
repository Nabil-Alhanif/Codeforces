#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9 + 7, INF = 1e18;
const double PI = acos(-1);

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, l, r, size, mid, pos, tmp;
    cin >> n;

    vector<int> berat;
    vector<int> mins;

    for (int i = 0; i < n; i++)
    {
        //cout << i << " ii\n";
        cin >> tmp;
        berat.push_back(tmp);
    }

    mins.push_back(berat[n - 1]);

    l = 0, r = 0, size = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        //cout << "i " << i << "\n";
        if (berat[i] < mins[size - 1])
        {
            mins.push_back(berat[i]);
            size++;
            continue;
        }

        l = 0, r = size, pos = 0;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (mins[mid] <= berat[i])
            {
                pos = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        mins[pos] = berat[i];
    }

    cout << mins.size() << "\n";
}
