class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size());
        stack<int> rec;

        for(int i = temperatures.size() - 1; i >= 0; i--){
            if(rec.empty()){
                ans[i] = 0;
                rec.push(i);
                continue;
            }

            if(temperatures[i] < temperatures[rec.top()]){
                ans[i] = rec.top() - i;
                rec.push(i);
            }

            else{
                while(!rec.empty() && temperatures[i] >= temperatures[rec.top()]){
                    rec.pop();
                }

                if(rec.empty()) ans[i] = 0;
                else ans[i] = rec.top() - i;
                
                rec.push(i);
            }
        }

        return ans;
    }
};
