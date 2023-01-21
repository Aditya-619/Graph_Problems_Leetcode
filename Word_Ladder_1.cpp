// Problem Link: https://leetcode.com/problems/word-ladder/description/

// Solution:

class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		int n = wordList.size();
		int m = wordList[0].size();
		set<string> st(wordList.begin(), wordList.end());

		queue<pair<string, int>> q;
		q.push({beginWord, 1});
		st.erase(beginWord);

		while (!q.empty()) {
			string word = q.front().first;
			int level = q.front().second;
			q.pop();

			if (word == endWord) {
				return level;
			}

			for (int i = 0; i < word.length(); i++) {
				char original = word[i];
				for (char c = 'a'; c <= 'z'; c++) {
					word[i] = c;
					if (st.find(word) != st.end()) {
						st.erase(word);
						q.push({word, level + 1});
					}
				}
				word[i] = original;
			}
		}
		return 0;
	}
};

// Time complexity: O(length of wordList) + O(length of word * 26) + O(logN)
//                                                                   for searching in the set

// Space complexity: O(length of the set)