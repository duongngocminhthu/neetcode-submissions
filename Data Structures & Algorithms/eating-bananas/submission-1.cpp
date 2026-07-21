class Solution {
public:
    bool check(int k,vector<int>& piles, int h){
        int hour = 0;

        for(int i = 0; i < piles.size(); i++){
            hour += (piles[i] + k - 1)/ k; // take note pp làm tròn ceil khá ảo
        }

        if(hour <= h) return true;
        else return false;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int k_right = 0;
        int k_left = 1;

        for(int i = 0; i < piles.size(); i++){
            if(piles[i] > k_right) k_right = piles[i];
        }

        while(k_left < k_right){
            int mid = k_left + (k_right - k_left)/2;

            if(check(mid,piles,h)) k_right = mid;

            else k_left = mid + 1;
        }

        return k_left;

    }
};
