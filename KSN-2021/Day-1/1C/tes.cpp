// Sunggu suram :D
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;

struct node {
    ll left;
    ll right;
    ll color;

    node()
    {
    }

    node(ll l, ll r)
    {
        this->left = l;
        this->right = r;
        this->color = 0;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    ll t, n, q, x, xb, col = 1;
    cin >> t >> n >> q;

    vector<ll> ans(n + 1);
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));

    cout << "? 1 " << n << "\n" << flush;
    cin >> x;
    dp[1][n] = x;

    if (x == 1) { // Artinya sama semua
        for (int i = 1; i <= n; i++)
            ans[i] = 1;
    }
    else {
        vector<node> segs;

        ll gl, gr;
        for (gl = 1, gr = 1; (gl <= gr) && (gr <= n); gr++) {

            // Di DP biar nggak buang buang operasi :D
            if (dp[gl][gr] == 0) {
                cout << "? " << gl << " " << gr << "\n" << flush;
                cin >> x;
                dp[gl][gr] = 0;
            }
            else x = dp[gl][gr];

            if (x == 2) {
                segs.push_back({gl, gr - 1});
                gl = gr;
            }
        }
        segs.push_back({gl, n});

        ll size = segs.size();

        /*
        for (auto i:segs)
            cout << i.left << " " << i.right << " lr\n";
        */

        if (dp[1][n] == 0) {
            cout << "? 1 " << n << "\n" << flush;
            cin >> x;
            dp[1][n] = x;
        }
        else x = dp[1][n];


        if (x == 2) { // Ada 2 warna totalnya
            for (auto &i:segs) {
                i.color = col;
                col ^= 1;
            }
        }
        else if (x == 3) { // Ada 3 warna totalnya
            bool f2, f3;
            for (int segidx = 0; segidx < size; segidx++) {
                //cout << segs[segidx].color << " sigcolor\n";
                if (segs[segidx].color != 0) // Artinya udah pernah dicatet sebelumnya
                    continue;

                segs[segidx].color = col;

                f2 = 0, f3 = 0;

                for (gl = segidx, gr = segidx; (gl <= gr) && (gr < size); gr++) {
                    if (dp[segs[gl].left][segs[gr].right] == 0) {
                        cout << "? " << segs[gl].left << " " << segs[gr].right << "\n" << flush;
                        cin >> x;
                        dp[segs[gl].left][segs[gr].right] = x;
                    }
                    else x = dp[segs[gl].left][segs[gr].right];

                    if (x == 2) {
                        if (f2) {
                            segs[gr].color = col;
                            gl = gr;
                            f2 = 0, f3 = 0;
                        }
                        else f2 = 1;
                    }
                    else if (x == 3) {
                        if (f3) {
                            // Coba cek apakah warna di gl sama gr itu sama atau nggak
                            if (dp[segs[gl + 1].left][segs[gr].right] == 0) {
                                cout << "? " << segs[gl + 1].left << " " << segs[gr].right << "\n" << flush;
                                cin >> x;
                                dp[segs[gl + 1].left][segs[gr].right] = x;
                            }
                            x = dp[segs[gl + 1].left][segs[gr].right];

                            if (x == 2) // Warnanya beda
                                continue;
                            else {
                                segs[gr].color = col;
                                gl = gr;
                                f2 = 0, f3 = 0;
                            }
                        }
                        else f3 = 1;
                    }
                }

                col++;
            }
        }
        else { // Ada 4 warna. Iya ini sekalian tc 3 dan 4 buat 35 poin :)
        }

        for (auto i:segs) {
            for (int j = i.left; j <= i.right; j++)
                ans[j] = i.color;
        }
    }


    cout << "!" << flush;
    for (int i = 1; i <= n; i++)
        cout << " " << ans[i] << flush;
    cout << "\n" << flush;
}
