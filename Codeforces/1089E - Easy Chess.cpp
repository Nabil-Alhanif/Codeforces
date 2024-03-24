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


void proc(pair<ll, ll> a)
{
    cout << (char)('a' + a.fi) << a.se + 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    vector<pair<ll, ll>> pos(64);

    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 6; y++) {
            if (y % 2)
                pos[y * 8 + 7 - x] = {x, y};
            else pos[y * 8 + x] = {x, y};
        }
    }

    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 2; y++) {
            if (x % 2)
                pos[48 + (x * 2 + 1 - y)] = {x, 6 + y};
            else pos[48 + (x * 2) + y] = {x, 6 + y};
        }
    }

    /*
    for (int i = 0; i < 64; i++)
        cout << i << " " << pos[i].fi << " " << pos[i].se << "\n";
    */

    int n;
    cin >> n;

    if (n <= 49) {
        for (int i = 0; i <= n - 2; i++) {
            proc(pos[i]);
            cout << " ";
        }

        if (pos[n - 2].fi == 7) {
            proc(pos[63]);
            cout << " ";
        }
        else {
            ll curx = pos[n - 2].fi;
            proc({curx, 7});
            cout << " ";
        }
    }
    else if (n <= 62) {
        for (int i = 0; i <= n - 2; i++) {
            proc(pos[i]);
            cout << " ";
        }

        // Cek dulu ini dia paling atas apa kagak
        if (pos[n].se == 7) {
            proc(pos[63]);
            cout << " ";
        }
        else {
            proc(pos[61]);
            cout << " ";
        }
    }
    else {
        for (int i = 0; i <= 59; i++) {
            proc(pos[i]);
            cout << " ";
        }
        proc(pos[63]);
        cout << " ";
        proc(pos[60]);
        cout << " ";
        proc(pos[61]);
        cout << " ";
    }

    proc(pos[62]);
    cout << "\n";
}
