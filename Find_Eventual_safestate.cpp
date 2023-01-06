// Problem Link: https://leetcode.com/problems/find-eventual-safe-states/description/


// There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i,

// meaning there is an edge from node i to each node in graph[i]. A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal

// node (or another safe node). Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.


// Constraints:

// n == graph.length
// 1 <= n <= 104
// 0 <= graph[i].length <= n
// 0 <= graph[i][j] <= n - 1
// graph[i] is sorted in a strictly increasing order.
// The graph may contain self-loops.
// The number of edges in the graph will be in the range [1, 4 * 104].


// Solution:

class Solution {
private:
	bool dfs(int src, vector<int> &vis, vector<int> &pathVis,
	         vector<vector<int>> &graph, vector<int> &check) {
		vis[src] = 1;
		pathVis[src] = 1;
		check[src] = 0;
		for (auto it : graph[src]) {
			if (!vis[it]) {
				if (dfs(it, vis, pathVis, graph, check) == true) {
					return true;
				}
			}
			else if (vis[it] == 1 && pathVis[it] == 1) {
				return true;
			}
		}
		check[src] = 1;
		pathVis[src] = 0;
		return false;
	}
public:
	vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
		int V = graph.size();
		vector<int> vis(V, 0);
		vector<int> pathVis(V, 0);
		vector<int> check(V, 0);
		vector<int> safeNode;
		for (int i = 0; i < V; i++) {
			if (!vis[i]) {
				dfs(i, vis, pathVis, graph, check);
			}
		}
		for (int i = 0; i < V; i++) {
			if (check[i] == 1) {
				safeNode.push_back(i);
			}
		}
		return safeNode;
	}
};