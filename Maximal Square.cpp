//Problem Link: https://leetcode.com/problems/maximal-square/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m));
        int ans=0;
        for(int i=n-1;i>=0;i--) {
            for(int j=m-1;j>=0;j--) {
                if(i==n-1 || j==m-1) {
                    if(matrix[i][j]=='1') dp[i][j]=1;
                    else dp[i][j]=0;
                }
                else {
                    if(matrix[i][j]=='0') 
                        dp[i][j]=0;
                    else {
                        dp[i][j]=min({dp[i][j+1],dp[i+1][j],dp[i+1][j+1]})+1;
                        
                    }
                }
                ans=max(ans,dp[i][j]);
            }
        }
        return ans*ans;
    }
};
