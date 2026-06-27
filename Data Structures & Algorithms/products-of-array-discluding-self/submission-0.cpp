class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> right(nums.size());
        vector<int> left;

        left.push_back(1);
        for(int i = 1; i < nums.size(); i++){
            left.push_back(left[i-1] * nums[i-1]);
        }

        right[nums.size()-1] = 1;
        for(int j = nums.size() - 2; j >= 0; j--){
            right[j] = right[j+1] * nums[j+1];
        }

        vector<int> ans (nums.size());

        for(int i = 0; i < nums.size(); i++){
            ans[i] = (left[i] * right[i]);
        }

        return ans;
    }
};
