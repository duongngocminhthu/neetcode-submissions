class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int length;
        int max_area = 0;

        for(int i = 0; i < heights.size(); i++){
            int left = i;
            int right = i;
            bool stop = false;

            while(!stop){
                if(left > 0 && heights[left - 1] >= heights[i]) left--;

                else if(right < heights.size() - 1 && heights[right + 1] >= heights[i]) right++;

                else stop = true;
            }

            length = (right - left) + 1;

            int area = length * heights[i];

            if(area > max_area) max_area = area;
        }

        return max_area;
    }        
};
