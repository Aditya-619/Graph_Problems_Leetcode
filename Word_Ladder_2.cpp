// Problem Link: https://practice.geeksforgeeks.org/problems/word-ladder-ii/1

// Solution:

class Solution {
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> st(wordList.begin(), wordList.end());
		queue<vector<string>> q;
		q.push({beginWord});

		vector<string> usedLevel;
		usedLevel.push_back(beginWord);
		int level = 0;

		vector<vector<string>> ans;

		while (!q.empty()) {
			vector<string> v = q.front();
			q.pop();
			if (v.size() > level) {
				level++;
				for (auto it : usedLevel) {
					st.erase(it);
				}
			}
			string word = v.back();

			if (word == endWord) {
				if (ans.size() == 0) {
					ans.push_back(v);
				} else if (ans[0].size() == v.size()) {
					ans.push_back(v);
				}
			}

			for (int i = 0; i < word.length(); i++) {
				char original = word[i];
				for (char c = 'a'; c <= 'z'; c++) {
					word[i] = c;
					if (st.find(word) != st.end()) {
						v.push_back(word);
						q.push(v);
						usedLevel.push_back(word);
						v.pop_back();
					}
				}
				word[i] = original;
			}
		}
		return ans;
	}
};