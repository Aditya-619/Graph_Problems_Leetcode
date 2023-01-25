// Problem Link: https://leetcode.com/problems/shortest-path-in-binary-matrix/description/

// Solution:

class Solution {
public:
	int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
		int n = grid.size();
		if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;
		if (n == 1 || n == 2) return n;
		vector<vector<int>> dist(n, vector<int> (n, 1e9));
		dist[0][0] = 0;
		queue<pair<int, pair<int, int>>> q;
		q.push({1, {0, 0}});

		int delRow[] = { -1, -1, 0, 1, 1, 1, 0, -1};
		int delCol[] = {0, 1, 1, 1, 0, -1, -1, -1};

		while (!q.empty()) {
			int d = q.front().first;
			int row = q.front().second.first;
			int col = q.front().second.second;
			q.pop();

			for (int i = 0; i < 8; i++) {
				int nrow = row + delRow[i];
				int ncol = col + delCol[i];
				if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n &&
				        grid[nrow][ncol] == 0) {

					if (d + 1 < dist[nrow][ncol]) {
						dist[nrow][ncol] = d + 1;
						if (nrow == n - 1 && ncol == n - 1) {
							return d + 1;
						}
						q.push({d + 1, {nrow, ncol}});
					}
				}
			}
		}
		return -1;
	}
};