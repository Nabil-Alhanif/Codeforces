#include "group.h"
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 1e12;

int getMinimumDelay(int N, vector<int> X, vector<int> Y) {
    ll minx = INF, miny = INF, maxx = -INF, maxy = -INF;

    vector<pair<ll, ll>> v;
    for (int i = 0; i < N; i++) {
        v.push_back({X[i] + Y[i], X[i] - Y[i]});
        minx = min(minx, (ll)(X[i] + Y[i]));
        miny = min(miny, (ll)(X[i] - Y[i]));
        maxx = max(maxx, (ll)(X[i] + Y[i]));
        maxy = max(maxy, (ll)(X[i] - Y[i]));
    }

    ll l = 0, r = 2e9, mid, ans = 0;
    bool c1, c2;
    while (l <= r) {
        mid = (l + r) / 2;
        c1 = 1, c2 = 1;

        for (auto i:v) {
            c1 &= (((i.first - minx <= mid) && (i.second - miny <= mid)) || ((maxx - i.first <= mid) && (maxy - i.second <= mid)));
            c2 &= (((i.first - minx <= mid) && (maxy - i.second <= mid)) || ((maxx - i.first <= mid) && (i.second - miny <= mid)));
        }

        if (c1 || c2) {
            r = mid - 1;
            ans = mid;
        }
        else l = mid + 1;
    }

    return ans;
}
