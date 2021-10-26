#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define P10_UINT64 10000000000000000000ULL   /* 19 zeroes */
#define E10_UINT64 19

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
            tree_order_statistics_node_update> indexed_set;

typedef int_fast64_t ll;
typedef __uint128_t u128_t;
typedef __int128_t i128_t;

const ll MOD = 1e9 + 7, INF = 1e18;
const double PI = acos(-1);

template <class T>
inline T ceil(T a, T b) // Get ceil of a / b
{
    if (b > 0)
        return ((a + b - 1) / b);
    return 0;
}

template <class T>
inline void printVect2D(vector<vector<T>> &vect)
{
    for (auto i:vect) {
        for (auto j:i)
            cout << j << " ";
        cout << "\n";
    }
    cout << "\n";
}

inline void sieve(vector<bool> &vect, bool is_one_prime)
{
    vect[0] = 1;
    if (!is_one_prime)
        vect[1] = 1;

    int_fast32_t lim = vect.size() - 1;
 
    for (int_fast32_t i = 2; i * i <= lim; i++) {
        if (!vect[i]) {
            for (ll j = i * i; j <= lim; j += i)
                vect[j] = 1;
        }
    }
}

inline vector<int> sieve(vector<bool> &vect)
{
    vector<int> ret;

    int_fast32_t size = vect.size();
    for (int_fast32_t i = 0; i <= size; i++) {
        if (!vect[i])
            ret.push_back(i);
    }

    return ret;
}

static void print_u128_u(u128_t u128)
{
    if (u128 > UINT64_MAX)
    {
        u128_t leading  = u128 / P10_UINT64;
        uint_fast64_t  trailing = u128 % P10_UINT64;
        print_u128_u(leading);
        cout << trailing;
    }
    else
    {
        uint_fast64_t u64 = u128;
        cout << u64;
    }
}



/* Question specific function and variable */

/* Note to self
 *
 * - Don't use a data structure when you don't need to
 */

const int N = 1e5 + 1;

int n, xs, ys, xf, yf, x, y, r, c, xe, ye;

vector<tuple<int, int, int, int>> pilar(N);
vector<int> dist(N, MOD);

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> xs >> ys >> xf >> yf;

    for (int i = 0; i < n; i++) {
        cin >> x >> y >> r >> c;
        pilar[i] = {x, y, r, c};
    }
    pilar[n] = {xf, yf, 0, 0};

    // dist, x, y, r, hor|ver
    priority_queue<tuple<int, int, int, int, bool>, vector<tuple<int, int, int, int, bool>>, greater<tuple<int, int, int, int, bool>>> pq; // Bool to denote vertical or horizontal. hor -> 0, ver -> 1
    pq.push({0, xs, ys, 0, 0});
    while (!pq.empty()) {
        auto [c, x, y, r, b] = pq.top();
        pq.pop();

        cout << x << " " << y << " " << r << " " << c << "\n";

        if ((x == xf) && (y == yf))
            return cout << c << "\n", 0;

        xe = x + r; // Kanan
        ye = y - r; // Bawah
        x -= r; // Kiri
        y += r; // Atas

        for (int i = 0; i <= n; i++) {
            auto [xi, yi, ri, ci] = pilar[i];
            if (b) { // Vertical
                if ((x <= xi + ri) && (xe >= xi - ri)) {
                    cout << "\n";
                    cout << i << " " << ri << " " << dist[i] << " iridist\n";
                    cout << x << " " << xe << " " << xi - ri << " " << xi + ri << " ver\n";
                    x = min(x, xi - ri);
                    xe = max(xe, xi + ri);
                    if (c < dist[i]) {
                        dist[i] = c;
                        pq.push({c + ci, xi, yi, ri, 0});
                    }
                    else c = dist[i];
                    cout << i << " " << ri << " " << dist[i] << " iridist\n";
                    cout << "\n";
                }
            }
            else { // Horizontal
                if ((ye <= yi + ri) && (y >= yi - ri)) {
                    cout << "\n";
                    cout << i << " " << ri << " " << dist[i] << " iridist\n";
                    cout << y << " " << ye << " " << yi + ri << " " << yi - ri << " hor\n";
                    y = max(y, yi + ri);
                    ye = min(ye, yi - ri);
                    if (c < dist[i]) {
                        dist[i] = c;
                       pq.push({c + ci, xi, yi, ri, 1});
                    }
                    else c = dist[i];
                    cout << i << " " << ri << " " << dist[i] << " iridist\n";
                    cout << "\n";
                }
            }
        }
    }
} 
