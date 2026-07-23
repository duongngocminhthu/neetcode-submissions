class Solution {
public:
    bool isPalindrome(string s) {
        string copy = "";

        for(char c : s){
            if(isalnum(c)){ 
                c = tolower(c);
                copy += c;
            }
        }

        int left = 0;
        int right = copy.length() - 1;

        while(left < right){
            if(copy[left] != copy[right]) return false;
            else{
                left++;
                right--;
            }
        }

        return true;
    }
};
