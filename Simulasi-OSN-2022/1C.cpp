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


inline ll ask(ll l, ll r)
{
    ll ret;
    cout << "? " << l << " " << r << "\n";
    cout << flush;
    cin >> ret;
    return ret;
}

set <ll> a, b;
void process1(ll l, ll r)
{
    if (l > r)
        return;

    ll mid = (l + r) / 2;
    ll res = ask(LIM, mid);

    if (res == 0) {
        b.insert(mid);
        process1(l, mid - 1);
        process1(mid + 1, r);
    }
    else {
        process1(l, mid - res);
        process1(mid + res, r);
    }
}

void process2(ll l, ll r)
{
    if (l > r)
        return;

    ll mid = (l + r) / 2;
    ll res = ask(mid, LIM);

    if (res == 0) {
        a.insert(mid);
        process2(l, mid - 1);
        process2(mid + 1, r);
    }
    else {
        process2(l, mid - res);
        process2(mid + res, r);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    process1(-1e8, 1e8);
    process2(-1e8, 1e8);

    cout << "! " << a.size() << " " << b.size() << "\n" << flush;
    for (auto i:a)
        cout << i << " " << flush;
    cout << "\n";
    for (auto i:b)
        cout << i << " " << flush;
    cout << "\n" << flush;
}
