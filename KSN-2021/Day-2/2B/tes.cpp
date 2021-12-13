#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef int_fast64_t ll;

//inline void merge(ll a, ll b);
inline ll find(ll a);

ll parent[(int)(1e5 + 1)], cnt[(int)(1e5 + 1)], a[(int)(1e5 + 1)], b[(int)(1e5 + 1)];
ll n, tmp, pa, pb;

/*
inline void merge(ll a, ll b)
{
    ll pa = find(a), pb = find(b);
    if (pa == pb)
        return;

    parent[pa] = pb;
    parent[a] = pb;
}
*/

inline ll find(ll a)
{
    if (parent[a] == a)
        return a;
    return (parent[a] = find(parent[a]));
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    for (int i = 0; i < n; i++)
        parent[i] = i;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            tmp = (a[i] ^ a[j]);
            if ((tmp > a[i]) && (tmp > a[j])) {
                pa = find(i);
                pb = find(j);
                if (pa == pb)
                    continue;
                parent[pa] = pb;
                parent[i] = pb;
            }
        }
    }

    for (int i = 0; i < n; i++)
        cnt[find(i)] += b[i];

    for (int i = 0; i < n; i++)
        cout << cnt[find(i)] << "\n";
}
