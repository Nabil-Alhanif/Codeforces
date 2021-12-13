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

struct node
{
    array<int, 26> letter;

    node()
    {
        for (auto &i:letter)
            i = 0;
    }

    node& operator=(const node &n)
    {
        for (int i = 0; i < 26; i++)
            this->letter[i] = n.letter[i];
        return *this;
    }
};

class segtree
{
public:
    int size;

    vector<node> data;
    vector<node> tree;

    segtree(string s)
    {
        this->size = s.size();
        this->data.resize(this->size);
        this->tree.resize(this->size * 4);

        for (auto &i:this->data) {
            for (auto &j:i.letter)
                j = 0;
        }

        for (auto &i:this->tree) {
            for (auto &j:i.letter)
                j = 0;
        }

        for (int i = 0; i < this->size; i++) {
            data[i].letter[s[i] - 'a'] = 1;
            cout << i << " " << s[i] - 'a' << " " << s[i] << " isi\n";
        }

        this->build(1, 0, this->size - 1);

        /*
        cout << "Tree after building\n";
        for (auto &i:this->tree) {
            for (auto &j:i.letter)
                cout << j << " ";
            cout << "\n";
        }
        */
    }

    void build(int vertex, int leftBound, int rightBound)
    {
        cout << vertex << " " << leftBound << " " << rightBound << " vlr\n";
        if (rightBound < leftBound)
            return;

        for (auto &i:this->data) {
            for (auto &j:i.letter)
                cout << j << " ";
            cout << "\n";
        }

        if (leftBound == rightBound) {
            this->tree[vertex] = this->data[leftBound];
            return;
        }

        int mid = (leftBound + rightBound) / 2;
        this->build(vertex * 2, leftBound, mid);
        this->build(vertex * 2 + 1, mid + 1, rightBound);

        this->tree[vertex] = this->merge(this->tree[vertex * 2], this->tree[vertex * 2 + 1]);
    }

    node merge(const node &a, const node &b)
    {
        node ret;
        for (int i = 0; i < 26; i++)
            ret.letter[i] = a.letter[i] + b.letter[i];
        return ret;
    }

    int get(int vertex, int leftIndex, int rightIndex, int leftBound, int rightBound, char search)
    {
        if ((rightBound < leftBound) || ((rightIndex < leftBound) || (leftIndex > rightBound)))
            return 0;

        if ((leftBound == leftIndex) && (rightBound == rightIndex))
            return this->tree[vertex].letter[search - 'a'];

        int mid = (leftBound + rightBound) / 2;
        if (leftIndex <= mid)
            return this->get(vertex * 2, leftIndex, rightIndex, leftBound, mid, search);
        else if (rightIndex > mid)
            return this->get(vertex * 2 + 1, leftIndex, rightIndex, mid + 1, rightBound, search);
        else return (this->get(vertex * 2, leftIndex, mid, leftBound, mid, search) +
                     this->get(vertex * 2 + 1, mid + 1, rightIndex, mid + 1, rightBound, search));
    }
};

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t, size;
    string s;

    cin >> t;
    while (t--) {
        cin >> size >> s;
        segtree stree(s);
        cout << "Selesai dibikin\n";
    }
}
