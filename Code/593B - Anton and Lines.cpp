#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9+7, INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, k, b, x1, x2;
    cin >> n >> x1 >> x2;

    vector<pair<ll, ll>> line(n);
    for (int i = 0; i < n; i++)
    {
        cin >> k >> b;

        // Get the y position of the line on x1 and x2
        line[i].first = (k * x1) + b;
        line[i].second = (k * x2) + b;
    }

    /**
     * Sort them so the next line y position when
     * intersecting with x1 is higher than the 
     * current line.
     *
     * To check if there are intersection, we just
     * need to check if the next line y position
     * when intersection with x2 is lower than
     * the current line.
     * If yes, then there are intersection.
     */
    sort(line.begin(), line.end());

    bool intersect = 0;
    for (int i = 1; i < n; i++)
    {
        if (line[i].second < line[i - 1].second)
            intersect = 1;
    }
    cout << (intersect ? "YES\n" : "NO\n");
}
