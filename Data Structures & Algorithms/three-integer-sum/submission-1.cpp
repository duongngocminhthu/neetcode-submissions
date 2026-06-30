class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // B1 : sort
        sort(nums.begin(),nums.end());

        vector<vector<int>> ans;
        unordered_set<int> group;

        // B2 : lặp
        for(int i = 0; i < nums.size(); i++){
            int left = i + 1;
            int right = nums.size() - 1;
            int key = -nums[i];

            if(group.count(nums[i])) continue;

            group.insert(nums[i]);
            
            while(left < right){
                int sum = nums[left] + nums[right];

                if(sum < key){
                    left++;
                }

                else if(sum > key){
                    right--;
                }

                else{
                    ans.push_back({nums[i],nums[left],nums[right]});
                    int cur = nums[left];
                    do{left++;}
                    while(left < right && nums[left] == cur);
                }
            }
        }

        return ans;
    }
};
