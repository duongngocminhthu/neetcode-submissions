class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> rec;
        vector<int> ans (temperatures.size());

        for(int i = 0; i < temperatures.size(); i++){
            while(!rec.empty() && temperatures[i] > temperatures[rec.top()]){
                ans[rec.top()] = i - rec.top();
                rec.pop();
            }

            rec.push(i);
        }

        return ans;
    }
};
