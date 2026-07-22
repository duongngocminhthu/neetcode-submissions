class TimeMap {
public:
    TimeMap() {
        
    }
     
    unordered_map <string,vector<pair<string,int>>> store;

    void set(string key, string value, int timestamp) {
        store[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        if(store.find(key) == store.end()){
            return "";
        }

        int left = 0;
        int right = store[key].size() - 1;
        int best = -1;
        int best_index = -1;

        while(left <= right){
            int mid = left + (right - left)/2;

            if(store[key][mid].second <= timestamp){
                if(store[key][mid].second > best){
                    best = store[key][mid].second;
                    best_index = mid;
                }

                left = mid + 1;
            } else{
                right = mid - 1;
            }
        }

        if(best != -1) return store[key][best_index].first;
        else return "";
    }
};
