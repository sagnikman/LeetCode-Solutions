//Problem Link: https://leetcode.com/problems/coin-change/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long long> dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<amount+1;i++) {
            for(int coin :coins) {
                if(i-coin>=0) {
                    dp[i]=min(dp[i],dp[i-coin]+1);
                }
            }
        }
        return dp[amount]==INT_MAX?-1:dp[amount];
    }
};
