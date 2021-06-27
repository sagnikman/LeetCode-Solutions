//Problem Link: https://leetcode.com/problems/word-break/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        bool dp[n+1];
        memset(dp,false,sizeof(dp));
        dp[n] = true;
        unordered_set<string> dict;
        for(auto w : wordDict) {
            dict.insert(w);
        }
        for(int i=n-1;i>=0;i--) {
            string word;
            for(int j=i;j<n;j++) {
                word.push_back(s[j]);
                if(dict.find(word)!=dict.end()) {
                    if(dp[j+1] == true) {
                    dp[i] = true;
                    }
                }
            }
        }
        return dp[0];
    }
};
