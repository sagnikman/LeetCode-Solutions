//Problem Link: https://leetcode.com/problems/house-robber/

class Solution {
public:
    int memo[101];
    int dp(int i,vector<int> &nums) {
        if(i>=nums.size()) return 0;
        if(memo[i]!=-1) return memo[i];
        int op1 = nums[i] + dp(i+2,nums);
        int op2 = dp(i+1,nums);
        return memo[i]=max(op1,op2);
    }
    int rob(vector<int>& nums) {
        memset(memo,-1,sizeof(memo));
        return dp(0,nums);
    }
};
