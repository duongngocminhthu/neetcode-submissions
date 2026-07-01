class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int left = 0;
        int right = height.size() - 1;
        int leftMax = height[left];
        int rightMax = height[right];

        while(left < right){
            leftMax = max(leftMax,height[left]);
            rightMax = max(rightMax,height[right]);

            if(leftMax <= rightMax){
                int water = leftMax - height[left];
                ans += water;
                left++;
            }

            else{
                int water = rightMax - height[right];
                ans += water;
                right--;
            }
        }

        return ans;
    }
};
