#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9+7, INF = 1e18;

class DSU
{
public:
    int population_size;
    vector<int> parent;
    vector<vector<int>> child;
    vector<vector<int>> adj_list;

    DSU(int n)
    {
        this->population_size = n;
        this->parent.resize(n+1);
        this->child.resize(n+1);
        this->adj_list.resize(n+1);

        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
            child[i].push_back(i);
        }
    }

    inline int find_set(int n)
    {
        return parent[n];
    }

    inline void combine(int a, int b)
    {
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
        a = parent[a];
        b = parent[b];

        if (a != b)
        {
            if (child[a].size() < child[b].size())
                swap(a, b);

            while (!child[b].empty())
            {
                int cur = child[b].back();
                child[b].pop_back();
                parent[cur] = a;
                child[a].push_back(cur);
            }
        }
    }
};

ll big_pow(ll base, ll pow)
{
    if (pow == 0)
        return 1;
    if (pow == 1)
        return (base % MOD);
    
    ll ret = big_pow(base, pow/2);
    if (pow % 2)
        ret = (((ret * ret) % MOD) * (base % MOD)) % MOD;
    else
        ret = (ret * ret) % MOD;
    return (ret % MOD);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n, tmp, cnt = 0;
        cin >> n;

        DSU yaDSU(n);
        map<int, int> top_row_map, bot_row_map;
        vector<int> top_row(n+1), bot_row(n+1);

        for (int i = 1; i <= n; i++)
        {
            cin >> top_row[i];
            top_row_map[top_row[i]] = i;
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> bot_row[i];
            bot_row_map[bot_row[i]] = i;
        }

        for (int i = 1; i <= n; i++)
        {
            yaDSU.combine(top_row[i], top_row[bot_row_map[top_row[i]]]);
        }

        for (int i = 1; i <= n; i++)
        {
            if (yaDSU.find_set(i) == i)
            {
                cnt++;
                /*
                cout << i << " : ";
                for (auto j:yaDSU.child[i])
                    cout << j << " ";
                cout << "\n";
                */
            }
        }

        cout << big_pow(2, cnt) << "\n";
    }
}
