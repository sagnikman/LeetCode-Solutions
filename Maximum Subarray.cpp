// Problem Link: https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int csum=0, msum=INT_MIN;
        for(int num:nums) {
            csum+=num;
            msum=max(csum,msum);
            if(csum<0) csum=0;
        }
        return msum;
    }
};
