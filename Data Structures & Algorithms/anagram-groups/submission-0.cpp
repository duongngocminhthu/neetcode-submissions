class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string,vector<string>> freq;
        for(int i = 0; i < strs.size(); i++){
            string key = strs[i];
            sort(key.begin(),key.end());
            freq[key].push_back(strs[i]);
        }

        vector<vector<string>> ans;

        for(auto p : freq){
            ans.push_back(p.second);
        }

        return ans;
    }
};
