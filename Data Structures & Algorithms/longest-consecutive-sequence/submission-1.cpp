class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> mp;
        int ans = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(!mp.count(nums[i])) 
                mp.insert(nums[i]);
        }

        for(int i = 0; i < nums.size(); i++){
            if(!mp.count(nums[i] - 1)){
                int len = 0;
                int init = nums[i];

                while(mp.count(init)){
                    len++;
                    init++;
                }

                ans = max(ans,len);
            }
        }

        return ans;
    }
};

