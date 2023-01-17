// Problem Link: https://practice.geeksforgeeks.org/problems/topological-sort/1

// Solution:

class Solution
{
private:
	void dfs(int src, vector<int> &vis, vector<int> adj[], stack<int> &st) {
		vis[src] = 1;
		for (auto it : adj[src]) {
			if (!vis[it]) {
				dfs(it, vis, adj, st);
			}
		}
		st.push(src);
	}
public:
	//Function to return list containing vertices in Topological order.
	vector<int> topoSort(int V, vector<int> adj[])
	{
		vector<int> vis(V, 0);
		stack<int> st;
		for (int i = 0; i < V; i++) {
			if (!vis[i]) {
				dfs(i, vis, adj, st);
			}
		}
		vector<int> ans;
		while (!st.empty()) {
			ans.push_back(st.top());
			st.pop();
		}
		return ans;
	}
};


// Time Complexity: O(V + E)
// Space Complexity: O(length of stack) + recursion stack space