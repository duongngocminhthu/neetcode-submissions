class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> unique;
        int left = 0;
        int best = 0;

        for(int right = 0; right < s.length(); right++){
            if(unique.count(s[right])){
                while(unique.count(s[right])){
                    unique.erase(s[left]);
                    left++;
                }
            }
            unique.insert(s[right]);

            best = max(best,right - left + 1);
        }

        return best;
    }
};
