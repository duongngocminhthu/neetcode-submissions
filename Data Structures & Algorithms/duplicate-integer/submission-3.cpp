class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> valid;
        for(int i = 0; i < nums.size(); i++){
            if(valid.count(nums[i])) return true;
            
            valid.insert(nums[i]);
            
        }

        return false;
    }
};