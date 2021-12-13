// KENAPA WA MULU YA ALLAH :CRY:
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef __int128_t i128_t;

const ll INF = 1e14;

class segkiri {
public:
    vector<pair<ll, ll>> tree;
    vector<ll> arr;
    ll size;

    segkiri(ll n)
    {
        this->size = n;
        this->tree.resize(n * 4 + 5);
        this->arr.resize(n);
    }

    pair<ll, ll> build(ll vertex, ll leftBound, ll rightBound)
    {
        if (leftBound > rightBound)
            return {-INF, -INF};

        if (leftBound == rightBound)
            this->tree[vertex] = {arr[leftBound], leftBound};
        else {
            ll mid = (leftBound + rightBound) / 2;
            this->tree[vertex] = this->merge(this->build(vertex * 2, leftBound, mid), this->build(vertex * 2 + 1, mid + 1, rightBound));
        }
        return this->tree[vertex];
    }

    pair<ll, ll> merge(pair<ll, ll> a, pair<ll, ll> b)
    {
        if (a.fi > b.fi)
            return a;
        else if (b.fi > a.fi)
            return b;
        else {
            if (a.se <= b.se)
                return a;
            else return b;
        }
    }

    pair<ll, ll> query(ll vertex, ll leftBound, ll rightBound, ll leftIndex, ll rightIndex)
    {
        if ((leftIndex > rightIndex) || ((leftIndex > rightBound) || (rightIndex < leftBound)))
            return {-INF, -INF};

        if ((leftIndex == leftBound) && (rightIndex == rightBound))
            return this->tree[vertex];

        ll mid = (leftBound + rightBound) / 2;
        if (rightIndex <= mid)
            return query(vertex * 2, leftBound, mid, leftIndex, rightIndex);
        else if (leftIndex > mid)
            return query(vertex * 2 + 1, mid + 1, rightBound, mid + 1, rightIndex);
        else return merge(query(vertex * 2, leftBound, mid, leftIndex, rightIndex), query(vertex * 2 + 1, mid + 1, rightBound, mid + 1, rightIndex));
    }
};

class segkanan {
public:
    vector<pair<ll, ll>> tree;
    vector<ll> arr;
    ll size;

    segkanan(ll n)
    {
        this->size = n;
        this->tree.resize(n * 4 + 5);
        this->arr.resize(n);
    }

    pair<ll, ll> build(ll vertex, ll leftBound, ll rightBound)
    {
        if (leftBound > rightBound)
            return {-INF, -INF};

        if (leftBound == rightBound)
            this->tree[vertex] = {arr[leftBound], leftBound};
        else {
            ll mid = (leftBound + rightBound) / 2;
            this->tree[vertex] = this->merge(this->build(vertex * 2, leftBound, mid), this->build(vertex * 2 + 1, mid + 1, rightBound));
        }
        return this->tree[vertex];
    }

    pair<ll, ll> merge(pair<ll, ll> a, pair<ll, ll> b)
    {
        if (a.fi > b.fi)
            return a;
        else if (b.fi > a.fi)
            return b;
        else {
            if (a.se >= b.se)
                return a;
            else return b;
        }
    }

    pair<ll, ll> query(ll vertex, ll leftBound, ll rightBound, ll leftIndex, ll rightIndex)
    {
        if ((leftIndex > rightIndex) || ((leftIndex > rightBound) || (rightIndex < leftBound)))
            return {-INF, -INF};

        if ((leftIndex == leftBound) && (rightIndex == rightBound))
            return this->tree[vertex];

        ll mid = (leftBound + rightBound) / 2;
        if (rightIndex <= mid)
            return query(vertex * 2, leftBound, mid, leftIndex, rightIndex);
        else if (leftIndex > mid)
            return query(vertex * 2 + 1, mid + 1, rightBound, mid + 1, rightIndex);
        else return merge(query(vertex * 2, leftBound, mid, leftIndex, rightIndex), query(vertex * 2 + 1, mid + 1, rightBound, mid + 1, rightIndex));
    }
};
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    ll n, q, s, t, ans;
    cin >> n;

    segkiri treekiri(n + 1);
    segkanan treekanan(n + 1);

    for (int i = 0; i < n; i++)
        cin >> treekiri.arr[i];
    treekanan.arr = treekiri.arr;

    treekiri.build(1, 0, n - 1);
    treekanan.build(1, 0, n - 1);

    ll pl, pr, jarak, selisih_tinggi, butuh_fuel, terbang_lurus;

    pair<ll, ll> res, res2;

    cin >> q;
    while (q--) {
        ans = 0;
        cin >> s >> t;
        s--, t--;

        if (s < t) {
            pl = s, pr = t;
            do {
                butuh_fuel = 0;
                /* Yang  kukhawatirkan adalah apabila ada sekumpulan yang tinggi nya sama
                 * jadi itu sama aja iterasi semua, so kayaknya bakal kena TLE
                 * but for now this should be sufficient
                 */
                res = treekiri.query(1, 0, n - 1, pl + 1, pr);
                res2 = treekanan.query(1, 0, n - 1, pl + 1, pr);

                jarak = abs(res.se - pl);
                selisih_tinggi = res.fi - treekiri.arr[pl];

                if (selisih_tinggi > 0)
                    butuh_fuel += (4 * selisih_tinggi);
                else if (selisih_tinggi < 0)
                    butuh_fuel += (-selisih_tinggi);

                terbang_lurus = max((ll)0, jarak - abs(selisih_tinggi));
                butuh_fuel += (terbang_lurus * 2);
                ans += butuh_fuel;

                jarak = abs(res2.se - res.se);
                butuh_fuel = jarak * 2;
                ans += butuh_fuel;
                //cout << ans << " " << butuh_fuel << " " << terbang_lurus << " " << jarak << " " << selisih_tinggi << " abftljst\n";

                pl = res2.se;
            }
            while (pl != pr);
            cout << ans << "\n";
        }
        else {
            pl = t, pr = s;
            do {
                butuh_fuel = 0;
                res = treekanan.query(1, 0, n - 1, pl, pr - 1);
                res2 = treekiri.query(1, 0, n - 1, pl, pr - 1);

                jarak = abs(pr - res.se);
                selisih_tinggi = res.fi - treekanan.arr[pr];

                if (selisih_tinggi > 0)
                    butuh_fuel += (4 * selisih_tinggi);
                else if (selisih_tinggi < 0)
                    butuh_fuel += (-selisih_tinggi);

                terbang_lurus = max((ll)0, jarak - abs(selisih_tinggi));
                butuh_fuel += (terbang_lurus * 2);
                ans += butuh_fuel;

                jarak = abs(res2.se - res.se);
                butuh_fuel = jarak * 2;
                ans += butuh_fuel;

                pr = res2.se;
            }
            while (pl != pr);
            cout << ans << "\n";
        }
    }
}
