// Problem Link: https://practice.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1 

// Solution:

class Solution {
  public:
    const int M = 1e5;
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        int n = arr.size();
        vector<int> dist(1e5, 1e9);
        dist[start] = 0;
        
        queue<pair<int, int>> q;
        q.push({0, start});
        while(!q.empty()) {
            int steps = q.front().first;
            int num = q.front().second;
            q.pop();
            
            for(auto it: arr) {
                int tmp = (num * it)%M;
                
                if(steps + 1 < dist[tmp]) {
                    dist[tmp] = steps + 1;
                    if(tmp == end) {
                        return steps+1;
                    }
                    q.push({steps+1, tmp});
                }
            }
        }
        return -1;
    }
};