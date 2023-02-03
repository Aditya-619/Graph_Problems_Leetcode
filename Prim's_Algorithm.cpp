// Problem Link: https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

// Solution:

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(V, 0);
        pq.push({0, 0});  // no need to carry parent as in the question it is asking only for sum
        
        int sum = 0;
        
        while(!pq.empty()) {
            auto it = pq.top();
            int wt = it.first;
            int node = it.second;
            pq.pop();
            
            if(vis[node] == 1) {
                continue;
            }
            
            vis[node] = 1;
            sum += wt;
            
            for(auto i: adj[node]) {
                int adjNode = i[0];
                int edgeWt = i[1];
                if(!vis[adjNode]) {
                    pq.push({edgeWt, adjNode});
                }
            }
        }
        return sum;
    }
};