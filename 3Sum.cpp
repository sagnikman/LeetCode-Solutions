// Problem Link: https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            int a = nums[i];
            int target = -a;
            int start = i+1, end = n-1;
            while(start < end) {
                if(nums[start] + nums[end] == target) {
                    result.push_back({nums[i],nums[start],nums[end]});
                    while(start<end && nums[start+1] == nums[start]) start++;
                    while(start<end && nums[end-1] == nums[end]) end--;
                    start++;
                    end--;
                }
                else if(nums[start] + nums[end] < target) start++;
                else end--;
            }
            while(i+1<n && nums[i+1]==nums[i]) i++;
        }
        return result;
    }
};
