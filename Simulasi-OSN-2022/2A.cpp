#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef int_fast64_t ll;
typedef uint_fast64_t ull;
typedef __uint128_t u128_t;
typedef __int128_t i128_t;

const ll LIM = 1e8;


class SegTree
{
    public:
        ll size;
        vector<ll> tree;

        SegTree(ll n)
        {
            this->size = n;
            this->tree.resize(n * 4 + 1, -1);
        }

        ll get(ll vertex, ll left_bound, ll right_bound, ll left_search, ll right_search)
        {
            if (left_bound > right_bound)
                return -1;
            if (left_search > right_search)
                return -1;

            if ((left_search == left_bound) && (right_search == right_bound))
                return this->tree[vertex];

            ll mid = (left_bound + right_bound) / 2;
            if (right_search <= mid)
                return get(vertex * 2, left_bound, mid, left_search, right_search);
            else if (left_search > mid)
                return get(vertex * 2 + 1, mid + 1, right_bound, left_search, right_search);
            else {
                ll left_side = get(vertex * 2, left_bound, mid, left_search, mid);
                ll right_side = get(vertex * 2 + 1, mid + 1, right_bound, mid + 1, right_search);
                return max(left_side, right_side);
            }
        }

        void update(ll vertex, ll left_bound, ll right_bound, ll target, ll value)
        {
            if (left_bound > right_bound)
                return;

            if (left_bound == right_bound) {
                this->tree[vertex] = value;
                return;
            }

            ll mid = (left_bound + right_bound) / 2;
            if (target <= mid)
                update(vertex * 2, left_bound, mid, target, value);
            else update(vertex * 2 + 1, mid + 1, right_bound, target, value);

            this->tree[vertex] = max(this->tree[vertex * 2], this->tree[vertex * 2 + 1]);
        }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, k;
    cin >> n >> k;

    vector<ll> nanas(n);
    for (int i = 0; i < n; i++)
        cin >> nanas[i];

    vector<vector<ll>> price(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> price[i][j];
    }

    for (int i = 1; i < n; i++)
        price[i][i] = price[i][i - 1];

    vector<pair<ll, ll>> limit(k);
    for (int i = 0; i < k; i++)
        cin >> limit[i].fi;
    for (int i = 0; i < k; i++)
        cin >> limit[i].se;

    vector<SegTree> dp(k + 1, SegTree(n));
    for (int i = 0; i < n; i++)
        dp[k].update(1, 0, n - 1, i, nanas[i]);

    /*
    for (int i = 0; i < n; i++)
        cout << dp[k].get(1, 0, n - 1, i, i) << " ";
    cout << "\n";
    */

    for (int gerak = k - 1; gerak >= 0; gerak--) {
        for (ll asal = 0; asal < n; asal++) {
            // Low bound
            ll lo = -1;
            for (ll l = 0, r = n - 1, mid = (l + r) / 2; l <= r; mid = (l + r) / 2) {
                if (price[asal][mid] < limit[gerak].fi)
                    l = mid + 1;
                else if (price[asal][mid] > limit[gerak].se)
                    r = mid - 1;
                else {
                    lo = mid;
                    r = mid - 1;
                }
            }
            // up bound
            ll hi = -2;
            for (ll l = 0, r = n - 1, mid = (l + r) / 2; l <= r; mid = (l + r) / 2) {
                if (price[asal][mid] < limit[gerak].fi)
                    l = mid + 1;
                else if (price[asal][mid] > limit[gerak].se)
                    r = mid - 1;
                else {
                    hi = mid;
                    l = mid + 1;
                }
            }

            //cout << gerak << " " << asal << " " << limit[gerak].fi << " " << limit[gerak].se << " " << lo << " " << hi << "\n";

            if ((lo < 0) || (hi < 0))
                continue;

            ll res;
            if ((hi < asal) || (lo > asal)) {
                // Jadi ini nggak kepotong gitu loh ges
                res = dp[gerak + 1].get(1, 0, n - 1, lo, hi);
            }
            else {
                ll left_side = dp[gerak + 1].get(1, 0, n - 1, lo, asal - 1);
                ll right_side = dp[gerak + 1].get(1, 0, n - 1, asal + 1, hi);
                res = max(left_side, right_side);
            }

            if (res != -1)
                dp[gerak].update(1, 0, n - 1, asal, res + nanas[asal]);
        }

        /*
        for (int i = 0; i < n; i++)
            cout << dp[gerak].get(1, 0, n - 1, i, i) << " ";
        cout << "\n";
        */
    }

    cout << dp[0].get(1, 0, n - 1, 0, 0) << "\n";
}
