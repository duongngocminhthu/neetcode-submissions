class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, maxFreq = 0;
        int res = 0;
        vector<int> charac (26,0);

        for(int right = 0; right < s.length(); right++){
            charac[s[right] - 'A']++;
            maxFreq = max(maxFreq,charac[s[right] - 'A']);

            int windowSize = right - left + 1;
            int change = windowSize - maxFreq;

            while(change > k){
                charac[s[left] - 'A']--;
                left++;
                windowSize--;

                maxFreq = 0;
                for(int i = 0; i < charac.size(); i++){
                    maxFreq = max(maxFreq,charac[i]);
                }

                change = windowSize - maxFreq;
            }

            res = max(res,windowSize);
        }
        return res;
    }
};
