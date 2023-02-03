// Problem Statement: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/

// Solution:

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> m(n, vector<int>(n, 1e9));
        for(auto it: edges) {
            m[it[0]][it[1]] = it[2];
            m[it[1]][it[0]] = it[2];
        }
        for(int i=0; i<n; i++) m[i][i] = 0;
        for(int via=0; via<n; via++) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    m[i][j] = min(m[i][j], m[i][via]+m[via][j]);
                }
            }
        }
        int cnt = n;
        int cityNum = -1;
        for(int i=0; i<n; i++) {
            int tmp=0;
            for(int j=0; j<n; j++) {
                if(m[i][j] <= distanceThreshold) {
                    tmp++;
                }
            }
            if(tmp <= cnt) {
                cnt = tmp;
                cityNum = i;
            }
        }
        return cityNum;
    }
};