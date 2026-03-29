class TimeMap {
private:
    unordered_map<string,vector<pair<int,string>>> mapus;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
         mapus[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(mapus.find(key) == mapus.end()){
            return "";
        }
        vector<pair<int,string>> here = mapus[key];
        int l = 0;
        int r = here.size()-1;
        string closest = "";
        while(l<=r){
            int m = l+(r-l)/2;
            if(here[m].first < timestamp){
                closest = here[m].second;
                l = m + 1;
            }else if(here[m].first > timestamp){
                r = m - 1;
            }else{
                return here[m].second;
            }
        }
        return closest;
    }
};
