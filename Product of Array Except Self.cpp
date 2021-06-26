class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product=1,productExcludingZero=1;
        int countOfZero=0;
        for(int num : nums) {
            product *= num;
            if(num == 0) {
                countOfZero++;
                continue;
            }
            productExcludingZero *= num;
        }
        if(countOfZero == 0) {
            for(int &num : nums) {
                num = product / num;
            }
            return nums;
        }
        else if(countOfZero == 1) {
            for(int &num : nums) {
                if(num == 0) num = productExcludingZero;
                else num = 0;
            }
            return nums;
        }
        else {
            for(int &num : nums) {
                num = 0;
            }
            return nums;
        }
    }
};
