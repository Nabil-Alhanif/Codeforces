#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t, n, size, l, r;

    cin >> t;

    while (t--) {
        cin >> n;
        size = 0;

        vector<char> s(n + 2);
        for (int i = 1; i <= n; i++)
            cin >> s[i];
        s[0] = '?';
        s[n + 1] = '?';

        vector<pair<int, int>> segment;
        for (int i = 1; i <= n; i++) {
            if (s[i] != '?') {
                if (size != 0)
                    segment.push_back({i - size, i - 1});
                size = 0;
            }
            else size++;
        }
        if (size != 0)
            segment.push_back({n - size + 1, n});

        for (auto i:segment) {
            l = i.first;
            r = i.second;

            if (s[l - 1] != '?') {
                for (int j = l; j <= r; j++) {
                    if ((j % 2) != (l % 2)) {
                        if (s[l - 1] == 'R')
                            s[j] = 'R';
                        else s[j] = 'B';
                    }
                    else {
                        if (s[l - 1] == 'R')
                            s[j] = 'B';
                        else s[j] = 'R';
                    }
                }
            }
            else if (s[r + 1] != '?') {
                for (int j = l; j <= r; j++) {
                    if ((j % 2) != (r % 2)) {
                        if (s[r + 1] == 'R')
                            s[j] = 'R';
                        else s[j] = 'B';
                    }
                    else {
                        if (s[r + 1] == 'R')
                            s[j] = 'B';
                        else s[j] = 'R';
                    }
                }
            }
            else {
                for (int j = l; j <= r; j++) {
                    if (j % 2)
                        s[j] = 'R';
                    else s[j] = 'B';
                }
            }
        }

        for (int i = 1; i <= n; i++)
            cout << s[i];
        cout << "\n";
    }
}
