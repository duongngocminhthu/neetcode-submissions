class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> bucket (nums.size() + 1);
        unordered_map <int,int> mp;
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }

        for(const auto&p : mp){
            bucket[p.second].push_back(p.first);
        }

        for(int i = bucket.size() - 1; i > 0; i--){
            for(int num : bucket[i]){
                    ans.push_back(num);
                    if(ans.size() == k) return ans;
            }
        }

        return ans;
    }
};
