class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> target (26,0);

        for(int i = 0; i < s1.length(); i++){
            int index = s1[i] - 'a';
            target[index]++;
        }

        for(int left = 0; left < s2.length(); left++){
            int right = left + s1.length() - 1;
            int curr = left;
            vector<int> window (26,0);

            if(right >= s2.length()) continue;

            while(curr <= right){
                int index = s2[curr] - 'a';
                window[index]++;
                curr++;
            }

            if(window == target) return true;
        }

        return false;
    }
};
