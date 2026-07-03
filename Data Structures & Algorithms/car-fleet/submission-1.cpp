class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> time;

        for(int i = 0; i < position.size(); i++){
            time.push_back({position[i],speed[i]});
        }

        sort(time.rbegin(),time.rend());
        vector<double> stack;

        for(auto& p : time){
            stack.push_back((double)(target - p.first) / p.second);
            if(stack.size() >= 2 && 
                stack.back() <= stack[stack.size() - 2])
                {
                    stack.pop_back();
                }
        }
        return stack.size();
    }
};
