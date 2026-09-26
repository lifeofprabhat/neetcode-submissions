class TimeMap {
public:
    map<string, map<int,string>> mp;

    TimeMap() {

        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].insert({timestamp, value});
        
    }
    
    string get(string key, int timestamp) {
        if(!mp.contains(key)) return "";
        auto& mp2 = mp[key];
        auto it = mp2.lower_bound(timestamp+1);
        if(it == mp2.begin()) return "";
        it--;
        return it->second;
        
    }
};
