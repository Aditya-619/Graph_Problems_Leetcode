// Problem Statement: https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph

// Solution:

class Solution {
public:
	vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
		vector<pair<int, int>> adj[n + 1];
		for (auto it : edges) {
			adj[it[0]].push_back({it[1], it[2]});
			adj[it[1]].push_back({it[0], it[2]});
		}
		vector<int> dist(n + 1, 1e9), parent(n + 1);
		dist[1] = 0;
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
		}
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push({0, 1});

		while (!pq.empty()) {
			auto it = pq.top();
			int d = it.first;
			int node = it.second;
			pq.pop();

			for (auto it : adj[node]) {
				int edgeWeight = it.second;
				int adjNode = it.first;

				if (d + edgeWeight < dist[adjNode]) {
					dist[adjNode] = d + edgeWeight;
					pq.push({d + edgeWeight, adjNode});
					parent[adjNode] = node;
				}
			}
		}
		if (dist[n] == 1e9) return { -1};
		vector<int> ans;
		int temp = n;
		while (parent[temp] != temp) {
			ans.push_back(temp);
			temp = parent[temp];
		}
		ans.push_back(1);
		reverse(ans.begin(), ans.end());
		return ans;
	}
};


// Time Complexity: O(E logV) + O(N)

