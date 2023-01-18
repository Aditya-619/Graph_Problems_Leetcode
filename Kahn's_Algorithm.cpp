// Problem Link: https://leetcode.com/problems/course-schedule/description/

// This problem is based on Kahn's Algorithm, the only change in this problem is you have to make the adjecency list according to the question

class Solution {
public:
	bool canFinish(int V, vector<vector<int>>& p) {
		vector<int> adj[V];
		for (int i = 0; i < p.size(); i++) {
			adj[p[i][1]].push_back(p[i][0]);
		}
		vector<int> indegree(V, 0);
		for (int i = 0; i < V; i++) {
			for (auto it : adj[i]) indegree[it]++;
		}
		queue<int> q;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) q.push(i);
		}
		vector<int> topo;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			topo.push_back(node);
			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}
		if (topo.size() != V) return false;
		return true;
	}
};

// Time complexity: O(V+E)
// space complexity: O(V) +        O(V) +                 O(V+E)
//                  for indegree  for pushing in queue     while loop part