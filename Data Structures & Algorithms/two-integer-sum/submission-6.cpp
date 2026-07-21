class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int,int> mp;

        for(int i = 0; i < nums.size(); i++){
            int need = target - nums[i];

            if(mp.contains(need)) return {mp[need],i};
            
            else mp[nums[i]] = i;
        }

        return {};
    }
};
