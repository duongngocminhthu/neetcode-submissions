class Solution {
public:

    string encode(vector<string>& strs) {
        string encode = "";

        for(string p : strs){
            encode +=  to_string(p.length()) + "#" + p;
        }

        return encode;
    }

    vector<string> decode(string s) {
        vector<string> decode;
        
        int i = 0;

        while(i < s.length()){
            int j = s.find("#",i);

            string len = s.substr(i,j-i);

            int num_len = stoi(len);

            decode.push_back(s.substr(j+1,num_len));

            i = j + num_len + 1;
        }

        return decode;
    }
};
