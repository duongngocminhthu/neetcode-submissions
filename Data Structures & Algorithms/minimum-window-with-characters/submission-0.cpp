class Solution {
public:
    string minWindow(string s, string t) {
        int need = 0, have = 0;
        string res = "";
        vector<int> count (126,0);
        vector<int> window (126,0);

        for(int i = 0; i < t.length(); i++){
            if(count[t[i]] == 0) need++;
            count[t[i]]++;
        }

        int right = 0, left = 0;
        
        while (right < s.size()) {
            // 1. Expand
            window[s[right]]++;
            
            if(window[s[right]] == count[s[right]]) have++;
    
            // 2. Nếu window đã hợp lệ
            while (have == need) {

                // cập nhật đáp án
                int len = right - left + 1;
                if(res.empty() || len < res.length()){
                    res = s.substr(left,len);
                }

                // shrink
                window[s[left]]--;

                if(window[s[left]] < count[s[left]]) have--;
                
                left++;
            }

            right++;
        }

        return res;
    }
};
