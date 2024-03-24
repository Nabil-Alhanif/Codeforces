#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define P10_UINT64 10000000000000000000ULL /* 19 zeroes */
#define E10_UINT64 19

#define fi first
#define se second

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using indexed_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef int_fast64_t ll;
typedef uint_fast64_t ull;
typedef __uint128_t u128_t;
typedef __int128_t i128_t;

const ll MOD = 1e9 + 7, INF = 1e15;
const double PI = acos(-1);


/* Question specific function and variable */

/* Note to self
 *
 * - Don't use a data structure when you don't need to
 * */


class DSU
{
    public:
        ll ans;
        ll cnt;
        ll size;

        vector<ll> segs;
        vector<ll> parent;
        map<ll, ll> data;

        DSU(ll n)
        {
            this->ans = 0;
            this->cnt = 0;
            this->size = n;

            this->segs.assign(n, 1);
            this->parent.resize(n);
            for (int i = 0; i < n; i++)
                this->parent[i] = i;
        }

        ll find(ll n)
        {
            if (n == this->parent[n])
                return n;
            return this->parent[n] = find(this->parent[n]);
        }

        void combine(ll a, ll b, ll dist, ll used)
        {
            ll pa = find(a), pb = find(b);
            if (pa != pb) {
                this->data[this->segs[pa]]--;
                this->data[this->segs[pb]]--;

                this->segs[pb] += this->segs[pa];
                this->data[this->segs[pb]]++;

                ll segs_cnt = this->data[this->segs[pb]];

                // Itung dia bisa masuk atau nggak
                if (segs_cnt * this->segs[pb] == used) {
                    if (segs_cnt > this->cnt) {
                        this->cnt = segs_cnt;
                        this->ans = dist + 1;
                    }
                }

                this->parent[pa] = pb;
            }
        }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;

    vector<ll> arr(n);
    vector<pair<ll, ll>> sorted(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sorted[i] = {arr[i], i};
    }
    sort(sorted.begin(), sorted.end());

    DSU yaDSU(n);

    // Base case buat jarak terpendek
    yaDSU.ans = sorted[0].fi + 1;
    yaDSU.cnt = 1;
    yaDSU.data[1] = 1;

    for (int i = 1; i < n; i++) {
        // Pertama anggep kalau dia jadi segmen sendiri dulu
        yaDSU.data[1]++;

        bool ada_temen = 0;
        if (sorted[i].se == n - 1) {
            if (arr[sorted[i].se - 1] <= sorted[i].fi) {
                yaDSU.combine(sorted[i].se, sorted[i].se - 1, sorted[i].fi, i + 1);
                ada_temen = 1;
            }
        }
        else {
            if (arr[sorted[i].se + 1] <= sorted[i].fi) {
                yaDSU.combine(sorted[i].se, sorted[i].se + 1, sorted[i].fi, i + 1);
                ada_temen = 1;
            }
            if (arr[sorted[i].se - 1] <= sorted[i].fi) {
                yaDSU.combine(sorted[i].se, sorted[i].se - 1, sorted[i].fi, i + 1);
                ada_temen = 1;
            }
        }

        // Kalau misal dia nggak bisa sambung siapa siapa
        if (!ada_temen) {
            // Artinya ini semua masih segmen 1
            if ((yaDSU.data[1] > yaDSU.cnt) && (yaDSU.data[1] == i + 1)) {
                yaDSU.cnt = yaDSU.data[1];
                yaDSU.ans = sorted[i].fi + 1;
            }
        }
    }

    cout  << yaDSU.ans << "\n";
}
