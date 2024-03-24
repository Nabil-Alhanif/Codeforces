#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second

using namespace std;
using namespace __gnu_pbds;

typedef int_fast64_t ll;
typedef uint_fast64_t ull;


class DSU
{
    public:
        ll size;
        vector<ll> parent;

        DSU(ll n)
        {
            this->size = n;
            this->parent.resize(n);
            for (int i = 1; i < n; i++)
                this->parent[i] = i;
        }

        ll find(ll n)
        {
            if (n == this->parent[n])
                return n;
            return this->parent[n] = find(this->parent[n]);
        }

        bool combine(ll a, ll b)
        {
            ll pa = find(a), pb = find(b);
            if (pa != pb) {
                this->parent[pa] = pb;
                return 1;
            }
            return 0;
        }
};

ll n, dist, u, v, a, b, q_cnt;
vector<pair<ll, ll>> ans;

ll ask(ll initial, ll l, ll r)
{
    assert(++q_cnt <= 2000);

    if (r < l)
        return 0;

    cout << "?";
    for (int i = 0; i < n; i++) {
        if (i == initial)
            cout << " 1";
        else if ((i >= l) && (i <= r))
            cout << " 2";
        else cout << " 0";
    }
    cout << "\n" << flush;

    ll ret;
    cin >> ret;
    return ret;
}

void check(ll initial, ll l, ll r) {
    if (r < l)
        return;

    ll get = ask(initial, l, r);
    ll harusnya = (r - l + 1) * b;

    if (get == harusnya)
        return;

    if (get == ((r - l + 1) * a)) {
        for (int i = l; i <= r; i++)
            ans.push_back({initial, i});
        return;
    }

    ll mid = (l + r) / 2;
    check(initial, l, mid);
    check(initial, mid + 1, r);
}

int main()
{
    cin >> n;

    ll satu, dua, tiga;

    a = 1, b = 2;

    for (int i = 0; i < n - 1; i++)
        check(i, i + 1, n - 1);

    DSU yaDSU(n);

    vector<pair<ll, ll>> rill;

    for (auto i:ans) {
        if (yaDSU.combine(i.fi, i.se))
            rill.push_back(i);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (yaDSU.combine(i, j))
                rill.push_back({i, j});
        }
    }

    ll size = rill.size();
    cout << "! " << size << "\n";
    for (int i = 0; i < size; i++)
        cout << rill[i].fi + 1 << " " << rill[i].se + 1 << "\n";
    cout << flush;
}
