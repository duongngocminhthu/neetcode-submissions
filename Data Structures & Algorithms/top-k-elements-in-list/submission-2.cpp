class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int,int> freq;
        for(int i = 0 ; i < nums.size(); i ++){
            freq[nums[i]]++;
        }

        vector<pair<int,int>> group;

        for(auto p : freq){
            group.push_back({p.second,p.first});
        }

        sort(group.begin(), group.end());

        vector<int> ans;

        for(int i = (int)group.size() - 1; i >= (int)group.size() - k; i--){
            ans.push_back(group[i].second);
        }
        
        return ans;
    }
};
