#include <bits/stdc++.h>
typedef int_fast64_t ll;
using namespace std;
ll INF = 1e18, MOD = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        bool is_empty = 1, valid_grid = 1;
        pair<int, int> first_char_coor;
        vector<vector<char>> grid(n, vector<char>(m));
        for (auto &row: grid)
        {
            for (auto &col: row)
            {
                cin >> col;
                if (is_empty && col != '.')
                {
                    is_empty = 0;
                    first_char_coor = {(&row - &grid[0]), (&col - &row[0])};
                    // cout << (&row - &grid[0]) << " " << (&col - &row[0]) << "\n";
                }
            }
        }

        if (is_empty)
        {
            for (int row = 0; row < n; row++)
            {
                for (int col = 0; col < m; col++)
                {
                    if ((row % 2) == (col % 2))
                        grid[row][col] = 'W';
                    else grid[row][col] = 'R';
                }
            }
        }
        else
        {
            queue<pair<int, int>> bfs;
            vector<vector<bool>> grid_visited(n, vector<bool>(m));

            bfs.push(first_char_coor);
            grid_visited[first_char_coor.first][first_char_coor.second] = 1;

            while (!bfs.empty())
            {
                int cur_row = bfs.front().first;
                int cur_col = bfs.front().second;
                char cur_char = grid[cur_row][cur_col];
                bfs.pop();

                // Check up
                if (cur_row - 1 >= 0)
                {
                    // Check if it's been filled and it has the same char as current grid
                    if (grid[cur_row - 1][cur_col] == cur_char)
                    {
                        valid_grid = 0;
                        break;
                    }

                    // Check if it's been visited. If not, visit it
                    if (!grid_visited[cur_row - 1][cur_col])
                    {
                        bfs.push({cur_row - 1, cur_col});
                        grid_visited[cur_row - 1][cur_col] = 1;
                        
                        if (cur_char == 'W')
                            grid[cur_row - 1][cur_col] = 'R';
                        else grid[cur_row - 1][cur_col] = 'W';
                    }
                }

                // Check down
                if (cur_row + 1 < n)
                {
                    // Check if it's been filled and it has the same char as current grid
                    if (grid[cur_row + 1][cur_col] == cur_char)
                    {
                        valid_grid = 0;
                        break;
                    }

                    // Check if it's been visited. If not, visit it
                    if (!grid_visited[cur_row + 1][cur_col])
                    {
                        bfs.push({cur_row + 1, cur_col});
                        grid_visited[cur_row + 1][cur_col] = 1;
                        
                        if (cur_char == 'W')
                            grid[cur_row + 1][cur_col] = 'R';
                        else grid[cur_row + 1][cur_col] = 'W';
                    }
                }

                // Check left
                if (cur_col - 1 >= 0)
                {
                    // Check if it's been filled and it has the same char as current grid
                    if (grid[cur_row][cur_col - 1] == cur_char)
                    {
                        valid_grid = 0;
                        break;
                    }

                    // Check if it's been visited. If not, visit it
                    if (!grid_visited[cur_row][cur_col - 1])
                    {
                        bfs.push({cur_row, cur_col - 1});
                        grid_visited[cur_row][cur_col - 1] = 1;
                        
                        if (cur_char == 'W')
                            grid[cur_row][cur_col - 1] = 'R';
                        else grid[cur_row][cur_col - 1] = 'W';
                    }
                }

                if (cur_col + 1 < m)
                {
                    // Check if it's been filled and it has the same char as current grid
                    if (grid[cur_row][cur_col + 1] == cur_char)
                    {
                        valid_grid = 0;
                        break;
                    }

                    // Check if it's been visited. If not, visit it
                    if (!grid_visited[cur_row][cur_col + 1])
                    {
                        bfs.push({cur_row, cur_col + 1});
                        grid_visited[cur_row][cur_col + 1] = 1;

                        if (cur_char == 'W')
                            grid[cur_row][cur_col + 1] = 'R';
                        else grid[cur_row][cur_col + 1] = 'W';
                    }
                }
            }
        }
        
        if (!valid_grid)
        {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        for (auto &row: grid)
        {
            for (auto &col: row)
                cout << col;
            cout << "\n";
        }
    }
}
