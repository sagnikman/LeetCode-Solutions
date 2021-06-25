class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==1) return intervals;
        vector<vector<int>> result;
        sort(intervals.begin(),intervals.end());
        vector<int> temp=intervals[0];
        for(auto p:intervals) {
            if(p[0]<=temp[1]) {
                temp[1]=max(p[1],temp[1]);
            }
            else {
                result.push_back(temp);
                temp=p;
            }
        }
        result.push_back(temp);
        return result;
    }
};