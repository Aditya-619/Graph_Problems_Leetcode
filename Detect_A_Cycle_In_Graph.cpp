
//Problrm Link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.

// Your task:
// You dont need to read input or print anything. Your task is to complete the function isCyclic() which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns a boolean value denoting if the given directed graph contains a cycle or not.


// Expected Time Complexity: O(V + E)
// Expected Auxiliary Space: O(V)


// Constraints:
// 1 ≤ V, E ≤ 10^5


// Solution:

class Solution {
private:
	bool dfs(int src, int vis[], int pathVis[], vector<int> adj[]) {
		vis[src] = 1;
		pathVis[src] = 1;

		for (auto it : adj[src]) {
			if (!vis[it]) {
				if (dfs(it, vis, pathVis, adj) == true) {
					return true;
				}
			}
			else if (vis[it] == 1 && pathVis[it] == 1) {
				return true;
			}
		}

		pathVis[src] = 0;
		return false;
	}
public:
	// Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) {
		int vis[V] = {0};
		int pathVis[V] = {0};

		for (int i = 0; i < V; i++) {
			if (!vis[i]) {
				if (dfs(i, vis, pathVis, adj)) {
					return true;
				}
			}
		}
		return false;
	}
};