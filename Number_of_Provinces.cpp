// Problem Link: https://leetcode.com/problems/number-of-provinces/description/

// Solution:

class DisjointSet {
	vector<int> rank, parent, size;
public:
	DisjointSet(int n) {
		rank.resize(n+1, 0);
		parent.resize(n+1);
		size.resize(n+1);
		for(int i=0; i<=n; i++) {
			parent[i] = i;
			size[i] = 1;
		}
	}

	int findParent(int node) {
		if(node == parent[node]) {
			return node;
		}
		return parent[node] = findParent(parent[node]);
	}

	void unionByRank(int u, int v) {
		int u_pu = findParent(u);
		int u_pv = findParent(v);
		if(u_pu == u_pv) {
			return;
		} 
		if(rank[u_pu] < rank[u_pv]) {
			parent[u_pu] = u_pv;
		} else if(rank[u_pv] < rank[u_pu]) {
			parent[u_pv] = u_pu;
		} else {
			parent[u_pv] = u_pu;
			rank[u_pv]++;
		}
	}

	void unionBySize(int u, int v) {
		int u_pu = findParent(u);
		int u_pv = findParent(v);
		if(u_pu == u_pv) {
			return;
		}
		if(size[u_pu] < size[u_pv]) {
			parent[u_pu] = u_pv;
			size[u_pv] += size[u_pu]; 
		} else {
			parent[u_pv] = u_pu;
			size[u_pu] += size[u_pv];
		}
	}
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        DisjointSet ds(V);

        for(int i=0; i<V; i++) {
            for(int j=0; j<V; j++) {
                if(isConnected[i][j] == 1) {
                    ds.unionBySize(i, j);
                }
            }
        }

        int count = 0;
        for(int i=0; i<V; i++) {
            if(ds.findParent(i) == i) count++;
        }

        return count;
    }
};