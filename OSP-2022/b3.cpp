#include <bits/stdc++.h>
#include <ios>
using namespace std;

#define fi first
#define se second

typedef int_fast64_t ll;

struct node
{
    ll val;
    pair<ll, ll> range;
    node *left;
    node *right;
};

class NabilTree
{
    public:
        node root;
        vector<ll> arr;

        NabilTree(ll n)
        {
            arr.resize(n + 1);
            root.range = {1, n};
            create(&root);
        }

        void create(node* cur)
        {
            if (cur->range.fi == cur->range.se) {
                cur->val = arr[cur->range.fi];
            }
            else {
                ll mid = (cur->range.fi + cur->range.se) / 2;
                cur->left = new node;
                cur->left->range = {cur->range.fi, mid};
                create(cur->left);
                cur->right = new node;
                cur->right->range = {mid + 1, cur->range.se};
                create(cur->right);
            }
        }

        ll assign(node* cur, ll left_bound, ll right_bound, ll val)
        {
            if (right_bound < left_bound)
                return 0;

            if (right_bound < cur->range.fi)
                return 0;

            if (left_bound > cur->range.se)
                return 0;

            // Cek kalau itu range sekarang
            if ((cur->range.fi == left_bound) && (cur->range.se == right_bound))
                cur->val = max(val, cur->val);

            ll mid = (cur->range.fi + cur->range.se) / 2;

            if (right_bound <= mid)
                cur->val = max(assign(cur->left, left_bound, right_bound, val), cur->val);
            else if (left_bound > mid)
                cur->val = max(assign(cur->right, left_bound, right_bound, val), cur->val);
            else {
                ll kiri = assign(cur->left, left_bound, mid, val);
                ll kanan = assign(cur->right, mid + 1, right_bound, val);
                cur->val = max(max(kiri, kanan), cur->val);
            }

            return cur->val;
        }

        ll get(node* cur, ll pos)
        {
            // Cek kalau itu range sekarang
            if ((pos >= cur->range.fi) && (pos <= cur->range.se))
                return cur->val;

            ll mid = (cur->range.fi + cur->range.se) / 2;
        }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, p, q, x, ans = 0;
    cin >> n >> p >> q;

    vector<ll> bebek(n), asli(n);
    for (int i = 0; i < n; i++) {
        cin >> bebek[i];
        asli[i] = bebek[i];
    }
    sort(bebek.begin(), bebek.end());

    /*
    cout << "Bebek: ";
    for (auto i:bebek)
        cout << i << " ";
    cout << "\n";
    */

    vector<ll> segment(n);
    for (int i = 0; i < n; i++) {
        ll pos = i;
        for (ll l = i, r = n - 1, mid = (l + r) / 2; l <= r; mid = (l + r) / 2) {
            if (bebek[i] + p >= bebek[mid]) {
                pos = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        segment[i] = pos;
    }

    /*
    for (int i = 0; i < n; i++)
        cout << i << " " << segment[i] << "\n";
    */

    NabilTree nabil(n);
    for (int i = 0; i < n; i++)
        nabil.assign(&nabil.root, i + 1, segment[i] + 1, segment[i] - i + 1);

    while (q--) {
        cin >> x;
        x--;
        ans = 0;

        ll pos = 0;
        for (ll l = 0, r = n - 1, mid = (l + r) / 2; l <= r; mid = (l + r) / 2) {
            if (bebek[mid] < asli[x])
                l = mid + 1;
            else if (bebek[mid] == asli[x]) {
                pos = mid;
                r = mid - 1;
            }
            else r = mid - 1;
        }

        /*
        for (int i = 0; i < n; i++) {
            if ((bebek[i] <= asli[x]) && (bebek[segment[i]] >= asli[x]))
                ans = max(ans, segment[i] - i + 1);
        }

        cout << ans << "\n";
        */
    }
}
