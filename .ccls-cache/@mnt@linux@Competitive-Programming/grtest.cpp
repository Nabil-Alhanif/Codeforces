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

typedef long double ld;
typedef int_fast64_t ll;
typedef uint_fast64_t ull;
typedef __uint128_t u128_t;
typedef __int128_t i128_t;

template <typename T>
using pt = complex<T>;
#define X real()
#define Y imag()

const ll MOD = 1e9 + 7, INF = LLONG_MAX;
const double PI = acos(-1);


/* Question specific function and variable */

/* Note to self
 *
 * - Don't use a data structure when you don't need to
 * */


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int V, E;
	cin >> V >> E;

	// Adjacency matrix
	/*
	int adj_mat[V][V];
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++)
			adj_mat[i][j] = 0;
	}

	for (int i = 0; i < E; i++) {
		int a, b;
		cin >> a >> b;
		adj_mat[a][b] = 1;
		adj_mat[b][a] = 1;
	}
	*/

	// Edge list
	/*
	pair<int, int> edge_list[E];
	for (int i = 0; i < E; i++)
		cin >> edge_list[i].first >> edge_list[i].second;
	*/

	// Adjacency list
	vector<int> adj_list[V];
	for (int i = 0; i < E; i++) {
		int a, b;
		cin >> a >> b;
		adj_list[a].push_back(b);
		adj_list[b].push_back(a);
	}

	stack<pair<int, int>> q;
	q.push({0, -1});

	while (!q.empty()) {
		int current = q.top().first;
		int parent = q.top().second;
		q.pop();

		cout << current << " -> ";

		for (auto i = adj_list[current].rbegin(); i != adj_list[current].rend(); i++) {
			if (*i != parent)
				q.push({*i, current});
		}
	}
	cout << "\n";
}

/*
10 9
0 1
1 2
1 3
1 4
2 5
3 6
4 7
4 8
5 9
*/
