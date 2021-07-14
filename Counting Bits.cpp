//Problem Link: https://leetcode.com/problems/counting-bits/

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1,0);
        for(int i=1;i<n+1;i++) {
            if(i&1) {
                dp[i]=dp[i/2]+1;
            }
            else dp[i]=dp[i/2];
        }
        return dp;
    }
};
