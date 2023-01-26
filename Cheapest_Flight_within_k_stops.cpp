// Problem Link: https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

// Solution:

class Solution {
public:
	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
		vector<pair<int, int>> adj[n];
		for (auto it : flights) {
			adj[it[0]].push_back({it[1], it[2]});
		}
		vector<int> cost(n, 1e9);
		cost[src] = 0;
		queue<pair<int, pair<int, int>>> q;
		q.push({0, {src, 0}});
		while (!q.empty()) {
			auto it = q.front();
			q.pop();
			int steps = it.first;
			int node = it.second.first;
			int c = it.second.second;

			if (steps > k) continue;

			for (auto i : adj[node]) {
				int adjNode = i.first;
				int edgeWeight = i.second;

				if (c + edgeWeight < cost[adjNode] && steps <= k) {
					cost[adjNode] = c + edgeWeight;
					q.push({steps + 1, {adjNode, c + edgeWeight}});
				}
			}
		}
		if (cost[dst] == 1e9) return -1;
		return cost[dst];
	}
};

// Time Complexity: O(E) -> total number of edges