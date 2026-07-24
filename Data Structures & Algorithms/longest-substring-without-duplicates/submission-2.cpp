class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> unique;
        int best = 0, left = 0;

        for(int right = 0; right < s.length(); right++){
            if(unique.find(s[right]) != unique.end()){
                left = max(unique[s[right]] + 1,left);
            }

            unique[s[right]] = right;

            best = max(best, right - left + 1);
        }

        return best;
    }
};
