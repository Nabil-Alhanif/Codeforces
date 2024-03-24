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

const ll MOD = 1e8, INF = 1e15;
const double PI = acos(-1);


/* Question specific function and variable */

/* Note to self
 *
 * - Don't use a data structure when you don't need to
 * */


struct node
{
    ll val;
    node* parent;
    vector<node*> child;

    node() {}
    node(ll n, node* par) {this->val = n; this->parent = par;}
};

void dfs(node *current, string past) {
    if (current->val != 0) {
        cout << past << current->val << "\n";
        stringstream ss;
        ss << current->val;
        string s;
        ss >> s;
        s += '.';
        past += s;
    }

    for (auto i:current->child)
        dfs(i, past);

    //past = past.substr(0, past.length() - 2);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        node root(0, nullptr);
        node *current = &root;
        node *last = &root;

        vector<ll> arr(n);
        for (auto i:arr) {
            cin >> i;
            if (i != 1) {
                while ((i - current->val != 1) && (current->val != 0))
                    current = current->parent;
                if (current->val != 0)
                    current = current->parent;
            }

            last = current;
            current = new node(i, last);
            last->child.push_back(current);
        }

        dfs(&root, "");
    }
}
