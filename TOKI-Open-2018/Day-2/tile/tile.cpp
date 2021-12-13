#include "tile.h"

#include <vector>
#include <bits/stdc++.h>

typedef int_fast64_t ll;

using namespace std;

ll n, k, q, m;
vector<ll> a;
vector<vector<ll>> dp;

void init(int N, int K, int Q, int M, std::vector<int> A) {
    n = N;
    k = K;
    q = Q;
    m = M;

    a.resize(m);
    for (int i = 0; i < m; i++)
        a[i] = A[i];

    dp.resize(m);
    for (auto &i:dp)
        i.resize(20);

    for (ll i = 0; i < m; i++) {
        // Cari posisi terkanan yang bakal masuk ke dalem grup dia
        dp[i][0] = m - 1;
        for (ll li = i, ri = m - 1, mid; li <= ri; ) {
            mid = (li + ri) / 2;
            if (a[mid] < a[i] + k) {
                dp[i][0] = mid;
                li = mid + 1;
            }
            else ri = mid - 1;
        }
    }

    for (ll j = 1; j <= 19; j++) {
        for (ll i = 0; i < m; i++) {
            if (dp[i][j - 1] + 1 >= m)
                dp[i][j] = m - 1;
            else
                dp[i][j] = dp[dp[i][j - 1] + 1][j - 1];
        }
    }

    /*
    for (auto i:dp) {
        for (auto j:i)
            cout << j << " ";
        cout << "\n";
    }
    cout << "\n";
    */
}

int getNumberOfSpecialTiles(int L, int R) {
    // Pertama binser cari tiles terkiri dan terkanan yang masuk
    // dalam l dan r
    ll li = 0, ri = m - 1, mid, lpos = m, rpos = -1;
    while (li <= ri) {
        mid = (li + ri) / 2;
        if (a[mid] >= L) {
            lpos = mid;
            ri = mid - 1;
        }
        else li = mid + 1;
    }

    li = 0, ri = m - 1;
    while (li <= ri) {
        mid = (li + ri) / 2;
        if (a[mid] <= R) {
            rpos = mid;
            li = mid + 1;
        }
        else ri = mid - 1;
    }

    //cout << lpos << " " << rpos << " " << L << " " << R << " lrlr\n";

    if (lpos > rpos) // Artinya nggak ada apa apa
        return 0;

    if ((R  - L + 1) <= k)
        return 1;

    ll ans = 1;
    for (ll i = 19, tmp;  (i >= 0) && (lpos <= rpos); i--) {
        if (dp[lpos][i] < rpos) {
            //cout << i << " " << dp[lpos][i] << " " << lpos << " idplpos\n";
            ans += (1 << i);
            lpos = dp[lpos][i] + 1;
        }
    }

    return ans;
}
