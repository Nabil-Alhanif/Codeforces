#include "radius.h"

#include <bits/stdc++.h>
using namespace std;

bool vis[100005];

std::vector<int> getRadius(int N, int Q,
        std::vector<int> U, std::vector<int> V, std::vector<int> A) {
    std::vector<int> ans;

    int maks = 0, u, v, x;

    vector<int> adj_list[N + 1];
    for (int i = 0; i < N - 1; i++) {
        adj_list[U[i]].push_back(V[i]);
        adj_list[V[i]].push_back(U[i]);
    }

    for (int i = 0; i < Q; i++) {
        queue <pair<int, int>> q;
        memset(vis, 0, N + 1);

        maks = 0;

        adj_list[A[i]].push_back(1);
        adj_list[1].push_back(A[i]);

        q.push({0, 1});
        vis[1] = 1;

        while (!q.empty()) {
            u = q.front().second;
            x = q.front().first;
            q.pop();
            maks = min(maks, x);

            //cout << u << " " << -x << " ux\n";

            for (auto i:adj_list[u]) {
                if (!vis[i]) {
                    vis[i] = 1;
                    q.push({x - 1, i});
                }
            }
        }

        ans.push_back(-maks);
        adj_list[A[i]].pop_back();
        adj_list[1].pop_back();
    }

    return ans;
}
