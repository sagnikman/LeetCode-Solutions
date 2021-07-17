//Problem Link: https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.size(),vector<bool>(s.size()));
        int len=-1;
        pair<int,int> ans;
        for(int g=0;g<s.size();g++) {
            for(int i=0,j=g;j<s.size();i++,j++) {
                if(g==0) {
                    dp[i][j]=true;
                }
                else if(g==1) {
                    if(s[i]==s[j]) 
                        dp[i][j]=true;
                }
                else {
                    if(s[i]==s[j] && dp[i+1][j-1]==true)
                        dp[i][j]=true;
                }
                if(dp[i][j]) {
                    if(g+1>len) {
                        len=g+1;
                        ans={i,j};     
                    }
                }
            }
        }
        string result;
        for(int i=ans.first;i<=ans.second;i++) {
            result.push_back(s[i]);
        }
        return result;
    }
};
