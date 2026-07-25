class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> target (26,0);
        vector<int> window (26,0);

        for(int i = 0; i < s1.length(); i++){
            int index = s1[i] - 'a';
            target[index]++;
        }

        int boundary = s2.length() - s1.length() + 1;
        for(int left = 0; left < boundary ; left++){
            int right = left + s1.length() - 1;
            int curr = left;

            if(left == 0){
                while(curr <= right){
                    int index = s2[curr] - 'a';
                    window[index]++;
                    curr++;
                }
            } else{
                window[s2[left-1] - 'a']--;
                window[s2[right] - 'a']++;
            }

            if(window == target) return true;
        }

        return false;
    }
};
