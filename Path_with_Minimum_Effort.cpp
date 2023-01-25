// Problem Link: https://leetcode.com/problems/path-with-minimum-effort/description/

// Solution:

class Solution {
public:
	int minimumEffortPath(vector<vector<int>>& heights) {
		int n = heights.size();
		int m = heights[0].size();
		priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
		               greater<pair<int, pair<int, int>>>> pq;

		pq.push({0, {0, 0}});

		vector<vector<int>> dist(n, vector<int> (m, 1e9));
		dist[0][0] = 0;

		int delRow[] = { -1, 0, 1, 0};
		int delCol[] = {0, 1, 0, -1};

		while (!pq.empty()) {
			auto it = pq.top();
			int row = it.second.first;
			int col = it.second.second;
			int diff = it.first;
			pq.pop();

			if (row == n - 1 && col == m - 1) {
				return diff;
			}

			for (int i = 0; i < 4; i++) {
				int newRow = row + delRow[i];
				int newCol = col + delCol[i];

				if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
					int newEffort = max(abs(heights[newRow][newCol] -
					                        heights[row][col]), diff);
					if (newEffort < dist[newRow][newCol]) {
						dist[newRow][newCol] = newEffort;
						pq.push({dist[newRow][newCol], {newRow, newCol}});
					}
				}
			}
		}
		return 0;
	}
};


// Time Complexity: n x m x 4 x log(n x m)