#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second

using namespace std;
using namespace __gnu_pbds;

typedef int_fast64_t ll;
typedef uint_fast64_t ull;


struct Node
{
    Node *front;
    Node *back;
    char cur;

    Node()
    {
        this->front = nullptr;
        this->back = nullptr;
    }
};

class LinkedList
{
    public:
        Node *begin, *end;

        LinkedList(ll cc, ll n)
        {
            this->begin = new Node;
            this->end = new Node;

            char c = (char)('A' + cc);

            cout << c << " " << cc << " " << n << "\n";

            this->begin->cur = c;
            Node *current = this->begin;

            for (int i = 1; i < n; i++) {
                Node *nc = new Node;

                nc->cur = c;
                nc->front = current;
                nc->back = current->back;

                current->back->front = nc;
                current->back = nc;

                current = nc;
            }

            this->end->front = current;
            current->back = this->end;
        }
};

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    string s;

    cin >> n >> s;

    vector<ll> cnt(26);
    for (int i = 0; i < n; i++)
        cnt[(int)(s[i] - 'A')]++;

    ll cnt_max = 0, cc = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] > cnt_max) {
            cnt_max = cnt[i];
            cc = i;
        }
    }
    cout << cc << " " << cnt[cc] << "\n";
    cnt[cc] = 0;
    cout << cnt[cc] << "\n";

    for (int i = 0; i < 26; i++)
        cout << cnt[i] << "\n";
    cout << "\n";

    LinkedList(cc, cnt_max);

    /*
    for (int i = 0, j = 0; i < cnt_max - 1; i++) {
        cout << j << " " << cnt[j] << " cntj\n";
        while (cnt[j] == 0) {
            cout << j << " jjj\n";
            j++;
        }

        while ((i < cnt_max - 1) && cnt[j]) {
            cout << i << " " << j << " ij\n";
            cnt[j]--;

            Node *nc = new Node;
            nc->cur = (char)('A' + j);
            nc->front = initial[i];
            nc->back = initial[i]->back;
            initial[i]->back->front = nc;
            initial[i]->back = nc;

            i++;
        }
    }
*/

    /*
    cur = ans.begin;
    while (cur != ans.end) {
        cout << cur->cur;
        cur = cur->back;
    }
    cout << "\n";
    */
}
