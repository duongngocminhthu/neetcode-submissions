class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0, slow = 0;
        
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);

        int head = 0;

        while(slow != head){
            slow = nums[slow];
            head = nums[head];
        } 
        
        return head;
    }
};
