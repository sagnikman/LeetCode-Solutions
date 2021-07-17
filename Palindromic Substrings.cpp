//Problem Link: https://leetcode.com/problems/palindromic-substrings/

class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<bool>> dp(n,vector<bool>(n));
        int count=0;
        for(int gap=0;gap<n;gap++) {
            for(int i=0,j=gap;j<n;i++,j++) {
                if(gap==0) {
                    dp[i][j]=true;
                }
                else if(gap==1) {
                    if(s[i]==s[j]) 
                        dp[i][j]=true;
                }
                else {
                    if(s[i]==s[j] && dp[i+1][j-1]==true) 
                        dp[i][j]=true;
                }
                if(dp[i][j]==true) count++;
            }
        }
        return count;
    }
};
