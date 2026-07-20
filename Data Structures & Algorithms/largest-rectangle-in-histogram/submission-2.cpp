class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> indices;
        int max_area = 0;

        for(int i = 0; i < heights.size(); i++){

            while(!indices.empty() &&
                  heights[indices.top()] > heights[i]){

                int height = heights[indices.top()];
                indices.pop();

                int width;

                if(indices.empty())
                    width = i;
                else
                    width = i - indices.top() - 1;

                max_area = max(max_area, height * width);
            }

            indices.push(i);
        }

        while(!indices.empty()){

            int height = heights[indices.top()];
            indices.pop();

            int width;

            if(indices.empty())
                width = heights.size();
            else
                width = heights.size() - indices.top() - 1;

            max_area = max(max_area, height * width);
        }

        return max_area;
    }
};