class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // BƯỚC 1 : SORT
        sort(nums.begin(),nums.end());

        // BƯỚC 2 : KIẾM TRÊN MẢNG ĐÃ SORT
        vector<vector<int>> ans;
        unordered_set<int> group;

        for(int i = 0; i < nums.size(); i++){
            if(group.contains(nums[i])) continue;
            else group.insert(nums[i]);

            int target = -nums[i];
            int left = i + 1;
            int right = nums.size() - 1;

            while(left < right){
                int sum = nums[left] + nums[right];

                if(sum > target) right--;

                else if(sum < target) left++;

                else{
                    ans.push_back({nums[i],nums[left],nums[right]});
                    int curr = nums[left];
                    do{ 
                        left++;
                    } while(left < right && nums[left] == curr);
                }
            }
        } 

        return ans;
    }
};
