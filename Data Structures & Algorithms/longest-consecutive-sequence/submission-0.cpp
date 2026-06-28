class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> group;

        for(int i = 0; i < nums.size(); i++){
            if(!group.count(nums[i]))
                group.insert(nums[i]);
        }

        int ans = 0;

        for(int i = 0; i < nums.size(); i++){
            if(!group.count(nums[i] - 1)){
                int num = nums[i];
                int len = 0;

                while(group.count(num)){
                    len++;
                    num++;
                }

                ans = max(ans,len);
            }
        }

        return ans;
    }
};
