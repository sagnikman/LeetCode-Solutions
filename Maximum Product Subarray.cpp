//Problem Link: https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currentMax=nums[0],currentMin=nums[0],overallMax=nums[0];
        for(int i=1;i<nums.size();i++) {
            int temp=currentMax;
            currentMax=max({nums[i],nums[i]*currentMax,nums[i]*currentMin});
            currentMin=min({nums[i],nums[i]*temp,nums[i]*currentMin});
            overallMax=max(overallMax,currentMax);
        }
        return overallMax;
    }
};
