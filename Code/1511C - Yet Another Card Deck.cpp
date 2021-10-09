#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9 + 7, INF = 1e18;
const double PI = acos(-1);

inline void sieve(vector<bool> &vect, int lim = 1e6)
{
    vect[0] = 1;
    vect[1] = 1;

    for (int i = 2; i * i <= lim; i++)
    {
        for (int j = i * i; j <= lim; j += i)
            vect[j] = 1;
    }
}

struct Node {
    int pos;
    struct Node* next;
    struct Node* prev;
};

void push(struct Node** head_ref, struct Node** tail_ref)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->pos = 1;

    new_node->next = (*head_ref);
    new_node->prev = NULL;

    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
    else (*tail_ref) = new_node;

    (*head_ref) = new_node;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n, q, tmp;
    cin >> n >> q;

    vector<int> color(51);
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;

        if (color[tmp] == 0)
            color[tmp] = i + 1;
    }

    while (q--)
    {
        cin >> tmp;

        for (auto &i:color)
        {
            if (i < color[tmp])
                i++;
        }

        cout << color[tmp] << " ";
        color[tmp] = 1;
    }

    cout << "\n";
}
