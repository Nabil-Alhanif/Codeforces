#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
            tree_order_statistics_node_update> indexed_set;

typedef int_fast64_t ll;
const ll MOD = 1e9 + 7, INF = 1e18;
const double PI = acos(-1);

template <class type>
inline void printVect2D(vector<vector<type>> &vect)
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

    ll lim = vect.size() - 1;
 
    for (ll i = 2; i * i <= lim; i++) {
        if (!vect[i]) {
            for (ll j = i * i; j <= lim; j += i)
                vect[j] = 1;
        }
    }
}

inline vector<int> sieve(vector<bool> &vect)
{
    vector<int> ret;

    ll size = vect.size();
    for (ll i = 0; i <= size; i++) {
        if (!vect[i])
            ret.push_back(i);
    }

    return ret;
}


/* Question specific function and variable */

/* Note to self
 *
 * - Don't use a data structure when you don't need to
 */

bool cmp(pair<int, int> &x, pair<int, int> &y)
{
    if (x.first == y.first)
        return x.second > y.second;
    return x.first < y.first;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    indexed_set ise;

    int n, m;
    cin >> n;

    vector<pair<int, int>> seq(n);
    for (int i = 0; i < n; i++) {
        cin >> seq[i].first;
        seq[i].second = i;
    }
    sort(seq.begin(), seq.end(), cmp);

    cin >> m;
    vector<pair<pair<int, int>, int>> query(m);
    for (int i = 0; i < m; i++) {
        cin >> query[i].first.first >> query[i].first.second;
        query[i].second = i;
    }
    sort(query.begin(), query.end());

    vector<int> ans(m);

    int idx = 1;
    for (auto i:query) {
        while (idx <= i.first.first) {
            ise.insert({seq[n - idx].second, seq[n - idx].first});
            idx++;
        }

        /*
        cout << "\n";
        for (auto j:ise)
            cout << j.first << " " << j.second << "\n";
        cout << "\n";
        */

        ans[i.second] = (*ise.find_by_order(i.first.second - 1)).second;
    }

    for (auto i:ans)
        cout << i << "\n";
}
