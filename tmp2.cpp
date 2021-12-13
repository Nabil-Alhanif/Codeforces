#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define P10_UINT64 10000000000000000000ULL   /* 19 zeroes */
#define E10_UINT64 19
 
#define fi first
#define se second
 
using namespace std;
using namespace __gnu_pbds;
 
template <typename T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag,
      tree_order_statistics_node_update>;

typedef int_fast64_t ll;
typedef uint_fast64_t ull;
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
inline T arithmeticSum(T a)
{
    return (((a * a) + a) / 2);
}
 
template <class T>
inline T arithmeticSum(T a, T b)
{
    return arithmeticSum(a) - arithmeticSum(b);
}
 
template <class T>
inline void printVect1D(vector<T> &vect)
{
    for (auto i:vect)
        cout << i << " ";
    cout << "\n";
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
 
template <class T>
inline void resizeVect1D(vector<T> &vect, int n)
{
    vect.resize(n);
}
 
template <class T>
inline void resizeVect2D(vector<vector<T>> &vect, int n, int m)
{
    vect.resize(n);
    for (auto &i:vect)
        i.resize(m);
}
 
static void print_u128_u(u128_t u128)
{
    if (u128 > UINT64_MAX)
    {
        u128_t leading  = u128 / P10_UINT64;
        ull trailing = u128 % P10_UINT64;
        print_u128_u(leading);
        cout << trailing;
    }
    else
    {
        ull u64 = u128;
        cout << u64;
    }
}

/* Question specific function and variable */

/* Note to self
 *
 * - Don't use a data structure when you don't need to
 */

struct point
{
    double x, y;

    point(){}

    point(double a, double b)
    {
        this->x = a;
        this->y = b;
    }

    bool operator<(const point &p)
    {
        if (this->x == p.x)
            return (this->y < p.y);
        return (this->x < p.x);
    }
};

int orientation(point a, point b, point c)
{
    double v = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
    if (v < 0)
        return -1;
    if (v > 0)
        return +1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    double s, f, n, d, dx, dy, ans = 0.0f;
    int tmp;

    cin >> s >> f >> n >> d;
    d /= 2;

    vector<point> arr;
    vector<point> cvh;

    resizeVect1D(arr, n);
    for (auto &i:arr)
        cin >> i.x >> i.y;
    arr.push_back({s, 0});
    arr.push_back({f, 0});

    sort(arr.begin(), arr.end());

    /*
    for (auto i:arr)
        cout << i.x << " " << i.y << "\n";
    */

    cvh.push_back(arr[0]);
    cvh.push_back(arr[1]);

    for (int i = 2; i <= n + 1; i++) {
        while ((cvh.size() >= 2) && orientation(*(cvh.end() - 2), cvh.back(), arr[i]))
            cvh.pop_back();
        cvh.push_back(arr[i]);
    }

    for (auto i:cvh)
        cout << i.x << " " << i.y << "\n";

    tmp = cvh.size();
    for (int i = 1; i < tmp; i++) {
        dx = (cvh[i].x - cvh[i - 1].x);
        dy = (cvh[i].y - cvh[i - 1].y);
        ans += sqrt((dx * dx) + (dy * dy));
    }
    cout << fixed << setprecision(3) << ans << "\n";
}
