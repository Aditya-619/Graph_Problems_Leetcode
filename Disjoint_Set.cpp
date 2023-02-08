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

// inside main()

   DisjointSet ds(7);
   ds.unionByRank(1, 2);
   ds.unionByRank(2, 3);
   ds.unionByRank(4, 5);
   ds.unionByRank(6, 7);
   ds.unionByRank(5, 6);
   // to check if 3 and 7 same or not
   if(ds.findParent(3) == ds.findParent(7)) {
   	cout << "Same" << endl;
   }else {
   	cout << "Not Same";
   }

   // DisjointSet ds(7);
   // ds.unionByUnion(1, 2);
   // ds.unionByUnion(2, 3);
   // ds.unionByUnion(4, 5);
   // ds.unionByUnion(6, 7);
   // ds.unionByUnion(5, 6);
   // // to check if 3 and 7 same or not
   // if(ds.findParent(3) == ds.findParent(7)) {
   // 	cout << "Same" << endl;
   // }else {
   // 	cout << "Not Same";
   // }