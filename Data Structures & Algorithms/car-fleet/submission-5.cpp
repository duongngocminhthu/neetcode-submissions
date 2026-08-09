class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> turn;
        stack<double> count;

        for(int i = 0; i < speed.size(); i++){
            turn.push_back({position[i],speed[i]});
        }

        sort(turn.rbegin(),turn.rend());

        for(int i = 0; i < speed.size(); i++){
            double time = (double)(target - turn[i].first) / turn[i].second;
            if(count.empty() || time > count.top()){
                count.push(time);
            }
        }

        return count.size();
    }
};
