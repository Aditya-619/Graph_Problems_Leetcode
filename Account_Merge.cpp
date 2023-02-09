// Problem Statement: https://leetcode.com/problems/accounts-merge/description/

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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> info;
        for(int i=0; i<n; i++) {
            for(int j=1; j<accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if(info.find(mail) == info.end()) {
                    info[mail] = i;
                } else {
                    ds.unionBySize(i, info[mail]);
                }
            }
        }
        vector<string> mergedMails[n];
        for(auto it: info) {
            string mail = it.first;
            int node = ds.findParent(it.second);
            mergedMails[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for(int i=0; i<n; i++) {
            if(mergedMails[i].size() == 0) continue;
            sort(mergedMails[i].begin(), mergedMails[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it: mergedMails[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    } 
};