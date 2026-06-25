class Solution {
public:
    bool isAnagram(string s, string t) {
    unordered_map <char,int> mp;

    for(int i = 0; i < s.length(); i++){
        mp[s[i]]++;
    }

    for(int j = 0; j < t.length(); j++){
        mp[t[j]]--;
    }

    for(auto p : mp){
        if(p.second != 0) 
            return false;
    }
    return true;
    }
};
