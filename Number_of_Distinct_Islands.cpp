
// Number of Distinct Islands.

// Time complexity -> n x m x log(n x m) * (n x m x 4)


class Solution {
private:
	void isValid(int row, int col, int n, int m) {
		if (row >= 0 && col >= 0 && row < n && col < m) {
			return 1;
		}
		return 0;
	}
	void dfs(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &vis,
	         vector<pair<int, int>> &v, int baseRow, int baseCol) {
		vis[r][c] = 1;
		v.push_back({r - baseRow, c - baseCol});

		int n = grid.size();
		int m = grid[0].size();

		int delRow[] = { -1, 0, 1, 0};
		int delCol[] = {0, -1, 0, 1};

		for (int i = 0; i < 4, i++) {
			int nrow = r + delRow[i];
			int ncol = c + delCol[i];
			if (isValid(nrow, ncol, n, m)) {
				if (!vis[nrow][ncol] && grid[nrow][ncol] == 1) {
					dfs(nrow, ncol, grid, vis, v, baseRow, baseCol);
				}
			}
		}
	}
public:
	int countDistinctIslands(vector<vector<int>> &grid) {
		int n = grid.size();
		int m = grid[0].size();
		vector<vector<int>> vis(n, vector<int> (m, 0));
		set<vector<pair<int, int>>> st;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {

				if (!vis[i][j] && grid[i][j] == 1) {

					vector<pair<int, int>> v;
					dfs(i, j, grid, vis, v, i, j);
					st.insert(v);
				}
			}
		}
		return st.size();
	}
};