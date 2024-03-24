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


struct query
{
    short type;
    ll time;
    ll val;
};

class FenTree
{
    public:
        ll size;
        vector<ll> bit;

        FenTree(ll n)
        {
            this->size = n + 1;
            this->bit.assign(n + 1, 0);
        }

        void add(ll idx, ll delta = 1)
        {
            for (; idx < this->size; idx += (idx & (- idx)))
                this->bit[idx] += delta;
        }

        ll get(ll idx)
        {
            if (idx < 0)
                return 0;

            ll ret = 0;
            for (; idx > 0; idx -= (idx & (-idx)))
                ret += this->bit[idx];
            return ret;
        }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    set<ll> initial_val;
    map<ll, ll> compressed_val;

    ll n;
    cin >> n;

    vector<query> queries(n);
    for (auto &i:queries) {
        cin >> i.type >> i.time >> i.val;
        initial_val.insert(i.val);
    }

    size_t cnt = 0;
    for (auto i:initial_val) {
        compressed_val[i] = cnt;
        cnt++;
    }

    ll val_count = cnt - 1;

    vector<set<ll>> initial_time(cnt + 1);
    map<ll, map<ll, ll>> compressed_time;

    for (auto i:queries)
        initial_time[compressed_val[i.val]].insert(i.time);

    for (int i = 0; i <= val_count; i++) {
        cnt = 1;
        for (auto j:initial_time[i]) {
            compressed_time[i][j] = cnt;
            cnt++;
        }
    }

    /*
    for (auto i:compressed_val)
        cout << "Actual val: " << i.fi << " compressed val: " << i.se << "\n";

    for (auto i:compressed_time) {
        for (auto j:i.se)
            cout << "Compressed val: " << i.fi << " actual time: " << j.fi << " compressed time: " << j.se << "\n";
    }
    */

    vector<FenTree> data;
    for (auto i:compressed_val)
        data.push_back(FenTree(compressed_time[i.se].size()));

    for (auto &i:queries) {
        //cout << "real: " << i.type << " " << i.val << " " << i.time << "\n";
        i.val = compressed_val[i.val];
        i.time = compressed_time[i.val][i.time];
        //cout << "transformed: " << i.type << " " << i.val << " " << i.time << "\n";

        if (i.type == 1) {
            data[i.val].add(i.time);
            //cout << "Add\n";
        }
        else if (i.type == 2) {
            data[i.val].add(i.time, -1);
            //cout << "Remove\n";
        }
        else {
            cout << data[i.val].get(i.time) << "\n";
            //cout << "Count\n";
        }

        /*
        cout << "Current data: ";
        for (auto j:data[i.val].bit)
            cout << j << " ";
        cout << "\n";
        */
    }
}
