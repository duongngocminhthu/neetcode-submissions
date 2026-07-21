class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> right (nums.size());
        vector<int> ans (nums.size());
        int left = 1;

        for(int i = nums.size() - 1; i >= 0; i--){
            if(i == nums.size() - 1) right[nums.size() - 1] = 1;
            else
                right[i] = nums[i+1] * right[i+1];
        }

        for(int i = 0; i < nums.size(); i++){
            if(i == 0) ans[0] = right[0];
            else
                left = left * nums[i-1];
                ans[i] = left * right[i];
        }

        return ans;
    }
};
